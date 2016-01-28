#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double median_rcpp(NumericVector x) {
  NumericVector y = clone(x);
  int n, half;
  double y1, y2;
  n = y.size();
  half = n / 2;
  if(n % 2 == 1) {
    // median for odd length vector
    std::nth_element(y.begin(), y.begin()+half, y.end());
    return y[half];
  } else {
    // median for even length vector
    std::nth_element(y.begin(), y.begin()+half, y.end());
    y1 = y[half];
    std::nth_element(y.begin(), y.begin()+half-1, y.begin()+half);
    y2 = y[half-1];
    return (y1 + y2) / 2.0;
  }
}

// [[Rcpp::export]]
NumericVector absolute_error_rcpp(NumericVector y_true, NumericVector y_pred) {
   return abs(y_true - y_pred);
}

// [[Rcpp::export]]
NumericVector percent_error_rcpp(NumericVector y_true, NumericVector y_pred) {
  return (y_true - y_pred) / y_true;
}

// [[Rcpp::export]]
NumericVector absolute_percent_error_rcpp(NumericVector y_true, NumericVector y_pred) {
  return abs(percent_error_rcpp(y_true = y_true, y_pred = y_pred));
}

// [[Rcpp::export]]
NumericVector squared_error_rcpp(NumericVector y_true, NumericVector y_pred) {
  return pow((y_true - y_pred), 2);
}

// [[Rcpp::export]]
double mean_error_rcpp(NumericVector y_true, NumericVector y_pred) {
  return mean((y_true - y_pred));
}

// [[Rcpp::export]]
double mean_absolute_error_rcpp(NumericVector y_true, NumericVector y_pred) {
  return mean(absolute_error_rcpp(y_true = y_true, y_pred = y_pred));
}

//' Calculate median absolute error regression loss.
//'
//' @param y_true Ground truth (correct) target values.
//' @param y_pred Estimated target values.
//' @return  A numeric vector of length one.
//' @export
// [[Rcpp::export]]
double median_absolute_error(NumericVector y_true, NumericVector y_pred) {
  return median_rcpp(absolute_error_rcpp(y_true = y_true, y_pred = y_pred));
}

//' Calculate mean percent error regression loss.
//'
//' @param y_true Ground truth (correct) target values.
//' @param y_pred Estimated target values.
//' @return  A numeric vector of length one.
//' @export
// [[Rcpp::export]]
double mean_percent_error(NumericVector y_true, NumericVector y_pred) {
  return mean(percent_error_rcpp(y_true = y_true, y_pred = y_pred));
}

//' Calculate median percent error regression loss.
//'
//' @param y_true Ground truth (correct) target values.
//' @param y_pred Estimated target values.
//' @return  A numeric vector of length one.
//' @export
// [[Rcpp::export]]
double median_percent_error(NumericVector y_true, NumericVector y_pred) {
  return median_rcpp(percent_error_rcpp(y_true = y_true, y_pred = y_pred));
}

//' Calculate mean squared error regression loss.
//'
//' @param y_true Ground truth (correct) target values.
//' @param y_pred Estimated target values.
//' @return  A numeric vector of length one.
//' @export
// [[Rcpp::export]]
double mean_squared_error(NumericVector y_true, NumericVector y_pred) {
  return mean(squared_error_rcpp(y_true = y_true, y_pred = y_pred));
}

//' Calculate median squared error regression loss.
//'
//' @param y_true Ground truth (correct) target values.
//' @param y_pred Estimated target values.
//' @return  A numeric vector of length one.
//' @export
// [[Rcpp::export]]
double median_squared_error(NumericVector y_true, NumericVector y_pred) {
  return median_rcpp(squared_error_rcpp(y_true = y_true, y_pred = y_pred));
}

//' Calculate mean absolute percent error regression loss.
//'
//' @param y_true Ground truth (correct) target values.
//' @param y_pred Estimated target values.
//' @return  A numeric vector of length one.
//' @export
// [[Rcpp::export]]
double mean_absolute_percent_error(NumericVector y_true, NumericVector y_pred) {
  return mean(absolute_percent_error_rcpp(y_true = y_true, y_pred = y_pred));
}

//' Calculate median absolute percent error regression loss.
//'
//' @param y_true Ground truth (correct) target values.
//' @param y_pred Estimated target values.
//' @return  A numeric vector of length one.
//' @export
// [[Rcpp::export]]
double median_absolute_percent_error(NumericVector y_true, NumericVector y_pred) {
  return median_rcpp(absolute_percent_error_rcpp(y_true = y_true, y_pred = y_pred));
}
