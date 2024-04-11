#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxa = 1e6 + 228;
const int sqmaxa = 1004;
int n;
vector<vector<int>> G(maxa);
vector<int> dist, parent;
int ans = 1e9;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vector<int> prime;
    for (int j = 2; j * j <= a; j++) {
      int cnt = 0;
      while (a % j == 0) {
        a /= j;
        cnt++;
      }
      if (cnt % 2 == 1) {
        prime.push_back(j);
      }
    }
    if (a != 1) {
      prime.push_back(a);
    }
    while (prime.size() < 2) {
      prime.push_back(1);
    }
    G[prime[0]].push_back(prime[1]);
    G[prime[1]].push_back(prime[0]);
  }
  for (int i = 1; i < maxa; i++) {
    sort(G[i].begin(), G[i].end());
    int was = G[i].size();
    G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
    if (was != G[i].size()) {
      ans = min(ans, 2);
    }
  }
  for (int i = 1; i < sqmaxa; i++) {
    if (G[i].empty()) {
      continue;
    }
    dist.assign(maxa, maxa);
    parent.assign(maxa, -1);
    dist[i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto u : G[v]) {
        if (dist[u] > dist[v] + 1) {
          dist[u] = dist[v] + 1;
          parent[u] = v;
          q.push(u);
        } else if (u != parent[v]) {
          ans = min(ans, dist[v] + 1 + dist[u]);
        }
      }
    }
  }
  cout << (ans == 1e9 ? -1 : ans) << '\n';
}