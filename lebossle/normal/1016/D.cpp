#include <bits/stdc++.h>
using namespace std;

// This code uses the bossle/cp library
// Available at https://github.com/bossle/cp

typedef long long int lli;

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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int& i : a)
    cin >> i;
  vector<int> b(m);
  for (int& i : b)
    cin >> i;
  int all=0;
  for (int i : a)
    all ^= i;
  int allb=0;
  for (int i : b)
    allb ^= i;
  if (all != allb) {
    cout << "NO" << endl;
    return 0;
  }
  vector<vector<int>> ans(n, vector<int> (m, 0));
  for (int i=1; i<n; ++i)
    ans[i][0] = a[i];
  for (int i=1; i<m; ++i)
    ans[0][i] = b[i];
  ans[0][0] = all^a[0]^b[0];
  cout << "YES" << endl;
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
      cout << ans[i][j] << (j==m-1 ? '\n' : ' ');
}