#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 200001;
const int kMaxK = 6;

int n;
int k;
vector<int> tree[kMaxN];

int f_count[kMaxN][kMaxK];
long long f_dist[kMaxN][kMaxK];

int temp_count[kMaxK];
long long temp_dist[kMaxK];

long long answer = 0ll;

void Dfs(int v, int ancestor) {
  f_count[v][0] = 1;

  for (int u : tree[v]) {
    if (u == ancestor) {
      continue;
    }

    Dfs(u, v);
    for (int i = 0; i < k; ++i) {
      temp_count[(i + 1) % k] = f_count[u][i];
      temp_dist[(i + 1) % k] = f_dist[u][i] + f_count[u][i];
    }

    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        int len_mod = (i + j) % k;

        long long total_count = f_count[v][i] * 1ll * temp_count[j];
        long long total_len = f_dist[v][i] * 1ll * temp_count[j] +
                              f_count[v][i] * 1ll * temp_dist[j];

        answer += (total_len - total_count * len_mod) / k;
        if (len_mod) {
          answer += total_count;
        }
      }
    }

    for (int i = 0; i < k; ++i) {
      f_count[v][i] += temp_count[i];
      f_dist[v][i] += temp_dist[i];
    }
  }
}

void Solve() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; scanf("%d%d", &u, &v);

    tree[u - 1].push_back(v - 1);
    tree[v - 1].push_back(u - 1);
  }

  Dfs(0, -1);

  cout << answer << "\n";
}

int main() {
  Solve();
  return 0;
}