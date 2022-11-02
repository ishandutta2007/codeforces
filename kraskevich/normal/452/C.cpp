#include <bits/stdc++.h>

using namespace std;

const int N = 1111;

double f1(int n, int m) {
  if (n == 1)
    return 0.0;
  return (n - 1) * (m - 1) * 1.0 / (n * m - 1) / n;
}

double f2(int n, int m) {
  return 1.0 / n;
}

int main() {
  ios_base::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  cout.setf(ios::fixed);
  cout.precision(10);
  cout << f1(n, m) + f2(n, m);

  return 0;
}