#include <iostream>
#include <map>
#include <complex>
#include <algorithm>
#include <cmath>
#define int long long
const int mxN = 8e5 + 734;
const double pi = acos(-1.0);
int lim, gay[mxN], freq[mxN];
std::complex<double> a[mxN], b[mxN];
void fft(std::complex<double> *poly, int deg) {
  // polynomials!
  for (int i = 0; i < lim; i++) {
    if (i < gay[i]) std::swap(poly[i], poly[gay[i]]);
  }
  for (int i = 1; i < lim; i <<= 1) {
    std::complex<double> w(cos(pi / i), sin(pi * deg / i)), aa, bb;
    for (int j = 0; j < lim; j += (i << 1)) {
      std::complex<double> omega(1, 0);
      for (int k = 0; k < i; k++, omega *= w) {
        aa = poly[j + k];
        bb = poly[i + j + k] * omega;
        poly[j + k] = aa + bb;
        poly[i + j + k] = aa - bb;
      }
    }
  }
}
int32_t main() {
  int n, x;
  std::cin >> n >> x;
  int arr[n + 1], ps[n + 1] = {};
  freq[0]++;
  for (int i = 1; i <= n; i++) {
    std::cin >> arr[i];
    ps[i] = ps[i - 1] + (arr[i] < x);
    freq[ps[i]]++;
  }
  for (int i = 0; i <= n; i++) {
    a[i] = freq[i];
    b[i] = freq[n - i];
  }
  int z = 0;
  for (lim = 1; lim <= n * 2; lim <<= 1) z++;
  for (int i = 0; i < lim; i++) gay[i] = (gay[i / 2] / 2 | ((i & 1) << (z - 1)));
  fft(a, 1);
  fft(b, 1);
  for (int i = 0; i < lim; i++) a[i] *= b[i];
  fft(a, -1);
  std::cout << (int) ((a[n].real() / lim - n + 0.5) / 2) << " ";
  for (int i = 1; i <= n; i++) std::cout << (int) (a[n + i].real() / lim + 0.5) << " ";
}