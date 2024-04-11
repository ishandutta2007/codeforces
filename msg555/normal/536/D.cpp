#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define INF 1000000000000000000LL
#define MAXN 2010

int N;
vector<pair<int, long long> > E[MAXN];
long long P[MAXN];

vector<long long> dijkstra(int s) {
  vector<long long> D(N, INF);
  D[s] = 0;
  priority_queue<pair<long long, int>> q;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    int u = q.top().second;
    long long ud = -q.top().first;
    q.pop();
    if (ud != D[u]) {
      continue;
    }

    for (int i = 0; i < E[u].size(); i++) {
      int v = E[u][i].first;
      long long vd = ud + E[u][i].second;
      if (vd < D[v]) {
        D[v] = vd;
        q.push(make_pair(-vd, v));
      }
    }
  }
  return D;
}

vector<long long> sd;
vector<long long> td;
vector<int> spi;
vector<int> tpi;

long long memo[2010][2010][2][2];

long long solve(int s, int t, int spos, int tpos, bool turn, bool candone) {
  if (spos == N || tpos == N) {
    return 0;
  }

  long long& ref = memo[spos][tpos][turn][candone];
  if (ref < INF) {
    return ref;
  }

  ref = -INF;
  if (candone) {
    sd.swap(td);
    spi.swap(tpi);
    ref = -solve(t, s, tpos, spos, !turn, false);
    sd.swap(td);
    spi.swap(tpi);
  }

  long long tdst = tpos == 0 ? -1 : td[tpi[tpos - 1]];

  int sz = 0;
  long long dv = 0;
  while (spos + sz < N && sd[spi[spos]] == sd[spi[spos + sz]]) {
    if (td[spi[spos + sz]] > tdst) {
      dv += P[spi[spos + sz]];
      candone = true;
    }
    ++sz;
  }
  ref = max(ref, dv + solve(s, t, spos + sz, tpos, turn, candone));
  return ref;
}

int main() {
  int M;
  cin >> N >> M;
  int s, t;
  cin >> s >> t;
  s--; t--;

  for (int i = 0; i < N; i++) {
    cin >> P[i];
    spi.push_back(i);
    tpi.push_back(i);
  }
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    E[u].push_back(make_pair(v, w));
    E[v].push_back(make_pair(u, w));
  }

  sd = dijkstra(s);
  td = dijkstra(t);
  sort(spi.begin(), spi.end(), [&](int x, int y) {
    return sd[x] < sd[y];
  });
  sort(tpi.begin(), tpi.end(), [&](int x, int y) {
    return td[x] < td[y];
  });

  memset(memo, 0x3F, sizeof(memo));
  long long r = solve(s, t, 0, 0, false, false);
  if (r > 0) {
    cout << "Break a heart\n";
  } else if (r == 0) {
    cout << "Flowers\n";
  } else {
    cout << "Cry\n";
  }

  return 0;
}