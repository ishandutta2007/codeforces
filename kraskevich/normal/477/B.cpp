#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> res(n);
  int m = 1;
  for (int i = 0; i < n; i++) {
    res[i].push_back(m);
    res[i].push_back(m + 2);
    res[i].push_back(m + 4);
    if ((m + 1) % 3 == 0)
      res[i].push_back(m + 3);
    else
      res[i].push_back(m + 1);
    m += 6;
  }
  cout << k * (m - 2) << "\n";
  for (int i = 0; i < n; i++) {
    for (int x : res[i])
      cout << x * k << " ";
    cout << "\n";
  }
  return 0;
}