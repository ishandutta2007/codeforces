#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

constexpr int N = 500;

int16_t dst[N][N];
int n;
using Vertices = basic_string<char32_t>;
Vertices allv;

map<Vertices, int> mc[N + 1];

void solve() {
  auto cv = allv;
  string s;
  int v, u;
  auto filter = [&]() { cv.erase(remove_if(cv.begin(), cv.end(), [&](int w) { return dst[v][w] <= dst[u][w]; }), cv.end()); };
  while (1) {
    int bv = -1, bd = 1e9;
    if (auto it = mc[cv.size()].find(cv); it != mc[cv.size()].end()) {
      bv = it->second;
    }
    if (bv == -1) {
      for (auto i: cv) {
        int cd = 0;
        for (auto j: cv) {
          cd += dst[i][j];
        }
        if (bd > cd) {
          bd = cd, bv = i;
        }
      }
      mc[cv.size()].emplace(cv, bv);
    }
    v = bv;
    cout << v + 1 << endl;
    cin >> s;
    if (s == "FOUND") {
      return;
    }
    cin >> u; --u;
    filter();
  }
}

vector<int> nei[N];

void bfs(int src) {
  static queue<int> q;
  q.push(src);
  while (q.size()) {
    int v = q.front(); q.pop();
    for (auto u: nei[v]) if (dst[src][u] > dst[src][v] + 1) {
      dst[src][u] = dst[src][v] + 1;
      q.push(u);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int m; cin >> n >> m;
  memset(dst, 63, sizeof dst);
  for (int i = 0; i < m; ++i) {
    int k, p, c; cin >> k >> p; --p;
    while (--k) {
      cin >> c; --c;
//      dst[p][c] = dst[c][p] = 1;
      nei[p].push_back(c);
      nei[c].push_back(p);
      p = c;
    }
  }
  for (int i = 0; i < n; ++i) {
    dst[i][i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    bfs(i);
  }
  allv.resize(n);
  iota(allv.begin(), allv.end(), 0);
  for (int it = 0; it < n; ++it) {
    solve();
  }
}