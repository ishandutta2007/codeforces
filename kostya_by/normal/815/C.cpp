#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 5005;
const long long kInf = (long long)1e18;

int n;
int b;
int c[kMaxN];
int d[kMaxN];

long long f[kMaxN][kMaxN][2];
long long g[kMaxN][2];

vector<int> children[kMaxN];
int subtree_sz[kMaxN];

void Dfs(int v) {
  subtree_sz[v] = 1;

  f[v][0][0] = 0;
  f[v][1][0] = c[v];
  f[v][1][1] = c[v] - d[v];

  for (int child : children[v]) {
    Dfs(child);

    for (int j = 0; j <= subtree_sz[v] + subtree_sz[child]; ++j) {
      for (int k = 0; k < 2; ++k) {
        g[j][k] = kInf;
      }
    }

    for (int j = 0; j <= subtree_sz[v]; ++j) {
      for (int k = 0; k <= subtree_sz[child]; ++k) {
        g[j + k][0] = min(g[j + k][0], f[v][j][0] + f[child][k][0]);

        g[j + k][1] = min(g[j + k][1], f[v][j][1] + f[child][k][1]);
        g[j + k][1] = min(g[j + k][1], f[v][j][1] + f[child][k][0]);
      }
    }

    subtree_sz[v] += subtree_sz[child];
    for (int j = 0; j <= subtree_sz[v]; ++j) {
      for (int k = 0; k < 2; ++k) {
        f[v][j][k] = g[j][k];
      }
    }
  }
}

void Solve() {
  cin >> n >> b;
  cin >> c[0] >> d[0];
  for (int i = 1; i < n; ++i) {
    int ancestor; cin >> c[i] >> d[i] >> ancestor;

    children[ancestor - 1].push_back(i);
  }

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k < 2; ++k) {
        f[i][j][k] = kInf;
      }
    }
  }

  Dfs(0);

  int answer = -1;
  for (int j = 0; j <= n; ++j) {
    if (min(f[0][j][0], f[0][j][1]) <= b) {
      answer = j;
    }
  }

  cout << answer << "\n";
}

int main() {
  int cases_num; cases_num = 1;

  for (int i = 0; i < cases_num; ++i) {
    Solve();
  }

  return 0;
}