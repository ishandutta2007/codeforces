#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100100;

int colors[MAX_N];
vector<int> vertices_with_color[2];
vector<int> graph[MAX_N];

bool is_bipartite;

void dfs(int v) {
  vertices_with_color[colors[v]].push_back(v);

  for (int u : graph[v]) {
    if (colors[u] == -1) {
      colors[u] = colors[v] ^ 1;
      dfs(u);
    } else {
      if ((colors[u] ^ colors[v]) != 1) {
        is_bipartite = false;
      }
    }
  }
}

void solve() {
  int n, m; scanf("%d%d", &n, &m);

  for (int i = 0; i < m; i++) {
    int u, v; scanf("%d%d", &u, &v);

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  memset(colors, -1, sizeof(colors));
  is_bipartite = true;

  for (int i = 1; i <= n; i++) {
    if (colors[i] != -1) {
      continue;
    }

    colors[i] = 0;
    dfs(i);
  }

  if (!is_bipartite) {
    printf("-1\n");
    return;
  }

  for (int c = 0; c < 2; c++) {
    printf("%d\n", (int) vertices_with_color[c].size());

    for (int v : vertices_with_color[c]) {
      printf("%d ", v);
    }
    printf("\n");
  }
}

int main() {
  solve();

  return 0;
}