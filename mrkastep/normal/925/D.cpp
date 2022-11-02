#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <queue>
#include <assert.h>
#include <functional>
#include <complex>
#include <unordered_map>
#include <iomanip>
#include <numeric>

using namespace std;

typedef long long ll;
typedef long double ld;

const long double PI = 3.141592653589793;
const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll INF2 = 1e17 + 10;
const ll mod = 1e9 + 7;

vector<ll> dist;
vector<vector<int> > tr;
vector<int> from;

int ans;
vector<int> path;

void bfs(int root) {
  queue<int> och;
  och.push(root);
  dist[root] = 0;
  from[root] = -1;
  while (!och.empty()) {
    int v = och.front();
    och.pop();
    for (auto w : tr[v]) {
      if (dist[w] == INF) {
        dist[w] = dist[v] + 1;
        from[w] = v;
        och.push(w);
      }
    }
  }
}

vector<int> comp;

void bfs1(int root) {
  queue<int> och;
  och.push(root);
  dist[root] = 0;
  from[root] = -1;
  while (!och.empty()) {
    int v = och.front();
    comp.push_back(v);
    och.pop();
    for (auto w : tr[v]) {
      if (dist[w] == INF) {
        dist[w] = dist[v] + 1;
        from[w] = v;
        och.push(w);
      }
    }
  }
}

void solve(istream& cin = cin, ostream& cout=cout) {
  int n, m;
  cin >> n >> m;
  dist.resize(n, INF);
  tr.resize(n);
  from.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    tr[a].push_back(b);
    tr[b].push_back(a);
  }
  ans = INF;
  path.clear();
  bfs(0);
  if (dist[n - 1] < INF) {
    int v = n - 1;
    while (v >= 0) {
      path.push_back(v + 1);
      v = from[v];
    }
    ans = path.size() - 1;
  }
  if (ans > 4) {
    for (int i = 0; i < n; ++i) {
      if (dist[i] == 2) {
        ans = 4;
        path.clear();
        path.push_back(n);
        path.push_back(1);
        path.push_back(i + 1);
        path.push_back(from[i] + 1);
        path.push_back(1);
        break;
      }
    }
  }
  if (ans > 5) {
    dist.assign(n, INF);
    from.assign(n, -1);
    dist[0] = INF - 1;
    int root = -1;
    bool fl = false;
    for (auto w: tr[0]) {
      if (dist[w] == INF) {
        comp.clear();
        bfs1(w);
        if (comp.size() > 2) {
          for (auto v: comp) {
            if (comp.size() > tr[v].size()) {
              root = v;
              fl = true;
              break;
            }
          }
        }
        if (fl)
          break;
      }
    }
    if (fl) {
      dist.assign(n, INF);
      from.assign(n, -1);
      dist[0] = INF - 1;
      bfs(root);
      for (int i = 0; i < n; ++i) {
        if (dist[i] == 2) {
          ans = 5;
          path.clear();
          path.push_back(n);
          path.push_back(root + 1);
          path.push_back(i + 1);
          path.push_back(from[i] + 1);
          path.push_back(root + 1);
          path.push_back(1);
          break;
        }
      }
    }
  }
  if (ans == INF) {
    cout << -1 << endl;
    return;
  }
  cout << ans << endl;
  reverse(path.begin(), path.end());
  for (auto w: path) {
    cout << w << ' ';
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  solve();
  return 0;
}