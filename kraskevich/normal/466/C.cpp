#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long s = 0;
  for (int i = 0; i < n; i++)
    s += a[i];
  if (s % 3) {
    cout << 0;
    return 0;
  }
  long long want = s / 3;
  s = 0;
  vector<int> suff;
  for (int i = n - 1; i >= 0; i--) {
    s += a[i];
    if (s == want)
      suff.push_back(i);
  }
  s = 0;
  reverse(suff.begin(), suff.end());
  long long res = 0;
  for (int i = 0; i < n; i++) {
    s += a[i];
    if (s == want) {
      auto it = upper_bound(suff.begin(), suff.end(), i + 1);
      res += (suff.end() - it);
    }
  }
  cout << res;
  return 0;
}