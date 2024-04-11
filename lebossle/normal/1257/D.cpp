#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a)
    cin >> i;
  int m;
  cin >> m;
  vector<pair<int, int>> sp(m);
  for (auto& p : sp) {
    cin >> p.second >> p.first;
  }
  
  sort(sp.begin(), sp.end());
  vector<pair<int, int>> goodSp;
  for (auto p : sp) {
    while (!goodSp.empty() && goodSp.back().second <= p.second)
      goodSp.pop_back();
    goodSp.push_back(p);
  }
  int cur=0, ans=0;
  while (cur != n) {
    ans++;
    int dist=0, maxPow=a[cur];
    for (int i=0; i<goodSp.size() && dist < goodSp[i].first && maxPow <= goodSp[i].second; ++i)
      while (cur+dist < n && dist < goodSp[i].first && maxPow <= goodSp[i].second) {
        dist++;
        maxPow = max(maxPow, a[cur+dist]);
      }
    if (dist == 0) {
      cout << -1 << endl;
      return;
    }
    cur += dist;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    solve();
  }
}