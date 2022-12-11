#include <bits/stdc++.h>
using namespace std;

// This code uses the bossle/cp library
// Available at https://github.com/bossle/cp

// #pragma STDC FENV_ACCESS OFF
// #pragma STDC FP_CONTRACT ON
// #pragma STDC CX_LIMITED_RANGE ON
// #pragma GCC optimize "O3"

namespace cp_base {

auto init = (
  ios::sync_with_stdio(false),
  cin.tie(nullptr)
);

}  // namespace cp_base

       

#define LOG(x) 

typedef long long int lli;

vector<vector<int>> g;
vector<int> depth;
vector<int> subtreeSize;

int dfs(int n, int p, int d) {
  depth[n] = d;
  subtreeSize[n] = 1;
  for (int c : g[n])
    if (c != p)
      subtreeSize[n] += dfs(c, n, d+1);
  return subtreeSize[n];
}

int main() {
  int n, k;
  cin >> n >> k;
  g.resize(n);
  for (int i=0; i<n-1; ++i) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  depth.resize(n);
  subtreeSize.resize(n);
  dfs(0, -1, 0);
  vector<lli> value(n);
  for (int i=0; i<n; ++i)
    value[i] = depth[i] - subtreeSize[i] + 1;
  sort(value.begin(), value.end());
  lli ans=0;
  for (int i=0; i<k; ++i)
    ans += value[n-1-i];
  cout << ans << endl;
}