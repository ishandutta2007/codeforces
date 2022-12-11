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

typedef long long int lli;
typedef long double llf;

       

#define LOG(x) 

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (auto& v : grid)
    for (int& i : v)
      cin >> i;
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j) {
      int goal = 4 - (i==0||i==n-1?1:0) - (j==0||j==m-1?1:0);
      if (grid[i][j] > goal) {
        cout << "NO" << '\n';
        return;
      }
      grid[i][j] = goal;
    }
  cout << "YES" << '\n';
  for (auto v : grid) {
    for (int i=0; i<m; ++i)
      cout << v[i] << (i==m-1?'\n':' ');
  }
}

int main() {
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta) {
    solve();
  }
}