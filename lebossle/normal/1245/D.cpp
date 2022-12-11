#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}

typedef long long int lli;

void solve() {
  int n;
  cin >> n;
  vector<lli> x(n), y(n);
  for (int i=0; i<n; ++i)
    cin >> x[i] >> y[i];
  vector<lli> c(n);
  for (lli& i : c)
    cin >> i;
  vector<lli> k(n);
  for (lli& i : k)
    cin >> i;
  vector<vector<lli> > cost(n+1, vector<lli>(n+1, 0));
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      cost[i][j] = (abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
  for (int i=0; i<n; ++i)
    cost[i][n] = cost[n][i] = c[i];
  priority_queue<pair<lli, pair<int, int>>> pq;
  vector<bool> vis(n+1, false);
  pq.push(make_pair(0LL, make_pair(n, n)));
  vector<pair<int, int>> ans;
  lli yen=0;
  while (!pq.empty()) {
    auto top = pq.top(); pq.pop();
    auto edge = top.second;
    int cur = edge.second;
    if (vis[cur])
      continue;
    vis[cur] = true;
    ans.push_back(edge);
    yen += -top.first;
    for (int i=0; i<n; ++i)
      pq.push(make_pair(-cost[cur][i], make_pair(cur, i)));
  }
  cout << yen << '\n';
  vector<int> power;
  for (auto p : ans)
    if (p.first == n && p.second != n)
      power.push_back(p.second);
  cout << power.size() << '\n';
  for (int p : power)
    cout << p+1 << ' ';
  cout << '\n';
  cout << n-power.size() << '\n';
  for (auto p : ans)
    if (p.first != n)
      cout << p.first+1 << ' ' << p.second+1 << '\n';
}