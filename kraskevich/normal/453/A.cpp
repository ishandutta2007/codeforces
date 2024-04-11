#include <bits/stdc++.h>

using namespace std;

double pw(double val, int n) {
  double res = 1.0;
  for (; n > 0; n /= 2) {
    if (n & 1)
      res *= val;
    val *= val;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);

  int m, n;
  cin >> m >> n;
  double res = 0.0;
  double s = 0.0;
  for (int v = m; v >= 1; v--) {
    double prob = 1.0 - pw((v - 1) * 1.0 / m, n);
    prob -= s;
    s += prob;
    res += prob * v;
  }
  cout.setf(ios::fixed);
  cout.precision(10);
  cout << res;

  return 0;
}