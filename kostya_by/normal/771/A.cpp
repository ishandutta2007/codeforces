#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 150001;

int n;
int m;
vector<int> graph[kMaxN];
bool is_visited[kMaxN];

int nodes_n = 0;
int edges_n = 0;

void Dfs(int v) {
  is_visited[v] = true;
  nodes_n += 1;
  edges_n += graph[v].size();

  for (int u : graph[v]) {
    if (!is_visited[u]) {
      Dfs(u);
    }
  }
}

void Solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b; scanf("%d%d", &a, &b);

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i) {
    if (is_visited[i]) {
      continue;
    }

    nodes_n = 0;
    edges_n = 0;

    Dfs(i);

    if ((long long)nodes_n * ((long long)nodes_n - 1) != edges_n) {
      printf("NO\n");
      exit(0);
    }
  }

  printf("YES\n");
}

int main() {
  Solve();
  return 0;
}