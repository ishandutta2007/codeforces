#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100100;

vector<int> children[MAX_N];
int f[MAX_N];
int d[MAX_N];

void dfs(int v) {
  f[v] = 1;

  for (int u : children[v]) {
    d[u] = d[v] + 1;

    dfs(u);

    f[v] += f[u];
  }
}

void solve() {
  int n; scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int p; scanf("%d", &p);

    children[p].push_back(i);
  }

  d[1] = 1;
  dfs(1);

  for (int i = 1; i <= n; i++) {
    int answer = 2 * d[i] + (n - f[i] - d[i] + 1);

    printf("%d.%d ", answer / 2, 5 * (answer % 2));
  }
  printf("\n");
}

int main() {
  solve();

  return 0;
}