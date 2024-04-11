#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)1e18;
const int N = (int)1e5 + 10;

vector<int> g[N];
vector<long long> w[N];
long long route[N];
long long d[N];
bool not_route[N];
int n, m, k;
int rem = 0;

typedef pair<long long, int> vertex;
#define F first
#define S second

int main() {
  ios_base::sync_with_stdio(0);

  cin >> n >> m >> k;
  fill(d, d + n, INF);
  fill(route, route + n, INF);
  for (int i = 0; i < m; i++) {
    int u, v, h;
    cin >> u >> v >> h;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
    w[u].push_back(h);
    w[v].push_back(h);
  }
  for (int i = 0; i < k; i++) {
    long long s, y;
    cin >> s >> y;
    --s;
    route[s] = min(route[s], y);
  }
  set<vertex> q;
  fill(not_route, not_route + N, true);
  d[0] = 0;
  q.insert(vertex(0, 0));
  for (int i = 1; i < n; i++)
    if (route[i] < INF) {
      not_route[i] = false;
      q.insert(vertex(route[i], i));
      d[i] = route[i];
    }
  while (q.size()) {
    int v = q.begin()->S;
    q.erase(q.begin());
    for (int i = 0; i < g[v].size(); i++) {
      int to = g[v][i];
      if (d[to] >= d[v] + w[v][i]) {
        not_route[to] = true;
        q.erase(vertex(d[to], to));
        d[to] = d[v] + w[v][i];
        q.insert(vertex(d[to], to));
      }
    }
  }
  for (int i = 0; i < n; i++)
    if (!not_route[i])
      rem++;
  cout << k - rem;

  return 0;
}