#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
  int n;
  cin >> n;
  vector<int> md(n);
  for (int i=0; i<n; ++i)
    cin >> md[i];
  vector<int> leaves;
  for (int i=0; i<n; ++i)
    if (md[i] == 1)
      leaves.push_back(i);
  vector<ii> ans;
  int curl = 2;
  for (int i=0; i<n; ++i) {
    if (leaves.size() < 2 && md[i] > 1) {
      leaves.push_back(i);
      md[i] = 1;
    } else {
      while (curl < leaves.size() && md[i] > 2) {
        ans.push_back(ii(i, leaves[curl]));
        md[i]--;
        curl++;
      }
    }
  }
  if (curl < leaves.size()) {
    cout << "NO" << endl;
    return 0;
  }
  int cur = leaves[0];
  int diam = 1;
  for (int i=0; i<n; ++i)
    if (md[i] >= 2) {
      ans.push_back(ii(i, cur));
      cur = i;
      diam++;
    }
  ans.push_back(ii(cur, leaves[1]));
  cout << "YES " << diam << "\n";
  cout << ans.size() << "\n";
  for (ii p : ans)
    cout << p.first+1 << ' ' << p.second+1 << "\n";
}