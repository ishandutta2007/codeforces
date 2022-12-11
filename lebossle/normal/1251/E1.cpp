#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, lli>> v(n);
  for (auto& p : v)
    cin >> p.first >> p.second;
  sort(v.begin(), v.end());
  priority_queue<pair<lli, int>> pq;
  int bought=0;
  lli ans=0;
  for (int i=v.size()-1; i>=0; --i) {
    pq.push(make_pair(-v[i].second, i));
    if (v[i].first > i+bought) {
      ans += -pq.top().first;
      pq.pop();
      bought++;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  for (int ta=0; ta<q; ++ta)
    solve();
}