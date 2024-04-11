#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v)
    cin >> i;
  map<int, int> lastOcc;
  int ans=n+1;
  for (int i=0; i<n; ++i) {
    if (lastOcc.count(v[i]))
      ans = min(ans, i-lastOcc[v[i]]+1);
    lastOcc[v[i]] = i;
  }
  cout << (ans==n+1 ? -1 : ans) << endl;
}

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    solve();
  }
}