#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  int res = 0;
  for (int i = 0; i < n; i++)
    if (a[i].second >= res)
      res = a[i].second;
    else
      res = a[i].first;
  cout << res << endl;
  return 0;
}