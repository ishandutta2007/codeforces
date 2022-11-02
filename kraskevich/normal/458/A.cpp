#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;

bool is_less(long long f0, long long f1) {
  if (f1 == 0)
    return f0 < 0;
  if (f1 < 0)
    return !is_less(-f0, -f1);
  long long L = 5 * f1 * f1;
  long long R = -2 * f0 - f1;
  if (R < 0)
    return false;
  return L < R * R;
}

int main() {
  ios_base::sync_with_stdio(0);

  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  while (a.length() < b.length() || max(a.length(), b.length()) < 2)
    a += '0';
  while (b.length() < a.length())
    b += '0';
  //cerr << a << " " << b << endl;
  int n = a.length();
  vector<long long> f(n);
  for (int i = n - 1; i >= 0; i--) {
    f[i] += a[i] - b[i];
    if (f[i] > INF) {
      cout << ">";
      return 0;
    }
    if (f[i] < -INF) {
      cout << "<";
      return 0;
    }
    if (i >= 2) {
      f[i - 1] += f[i];
      f[i - 2] += f[i];
    }
  }
  if (f[0] == 0 && f[1] == 0) {
    cout << "=";
    return 0;
  }
  if (is_less(f[0], f[1]))
    cout << "<";
  else
    cout << ">";

  return 0;
}