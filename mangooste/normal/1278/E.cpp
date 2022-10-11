#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Main();
#ifdef LOCAL
  cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

int n;
vector<vector<int>> G;
vector<int> L, R;
int max_r;

void dfs(int v, int pr) {
  int cnt = 0;
  for (auto u : G[v]) {
    if (u != pr) {
      cnt++;
    }
  }
  L[v] = max_r - cnt;
  int cur_r = L[v] + 1;
  max_r = min(max_r, L[v] - 1);
  for (auto u : G[v]) {
    if (u != pr) {
      R[u] = cur_r++;
      dfs(u, v);  
    }
  }
}

void Main() {
  cin >> n;
  G.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    G[v].push_back(u);
    G[u].push_back(v);
  }
  L.resize(n);
  R.resize(n);
  max_r = 2 * n - 1;
  R[0] = 2 * n;
  dfs(0, 0);
  for (int i = 0; i < n; i++) {
    cout << L[i] << ' ' << R[i] << '\n';
  }
}