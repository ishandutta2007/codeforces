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

int main() {
  int n;
  cin >> n;
  vector<string> inp(n);
  for (string& s : inp)
    cin >> s;
  vector<pair<int, int>> piece;
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      if (inp[i][j] == 'o')
        piece.push_back({i, j});
  vector<string> ans(2*n-1, string(2*n-1, 'x'));
  ans[n-1][n-1] = 'o';
  vector<string> attacked(n, string(n, '.'));
  for (int i=-n+1; i<n; ++i)
    for (int j=-n+1; j<n; ++j)
      for (auto p : piece) {
        int x = p.first+i, y = p.second+j;
        if (x < 0 || n <= x || y < 0 || n <= y)
          continue;
        if (inp[x][y] == '.')
          ans[n-1+i][n-1+j] = '.';
      }
  for (int i=-n+1; i<n; ++i)
    for (int j=-n+1; j<n; ++j)
      for (auto p : piece) {
        int x = p.first+i, y = p.second+j;
        if (x < 0 || n <= x || y < 0 || n <= y)
          continue;
        if (ans[n-1+i][n-1+j] == 'x')
          attacked[x][y] = 'x';
      }
  LOG(ans);
  LOG(attacked);
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      if (inp[i][j] == 'x' && attacked[i][j] == '.' || inp[i][j] == '.' && attacked[i][j] == 'x')  {
        cout << "NO" << endl;
        return 0;
      }
  cout << "YES" << endl;
  for (string s : ans)
    cout << s << endl;
}