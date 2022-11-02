#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;

double calc(const vector<double> &v) {
  double prod = 1.0;
  double res = 0.0;
  for (int i = 0; i < v.size(); i++)
    prod *= 1.0 - v[i];
  for (int i = 0; i < v.size(); i++)
    res += v[i] * prod / (1 - v[i]);
  return res;
}

int main() {
  #ifdef TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<double> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    if (fabs(v[i] - 1.0) < eps) {
      cout << 1;
      return 0;
    }
  }
  sort(v.rbegin(), v.rend());
  vector<double> cur;
  double res = 0.0;
  for (int i = 0; i < v.size(); i++) {
    cur.push_back(v[i]);
    res = max(res, calc(cur));
  }
  cout.precision(20);
  cout << res;
  return 0;
}