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
  int n,  m;
  cin >> n >> m;
  vector<string> inp(n);
  for (string& s : inp)
    cin >> s;
  vector<vector<int>> maxtl(n, vector<int>(m));
  for (int i=n-1; i>=0; --i)
    for (int j=m-1; j>=0; --j)
      if (inp[i][j] == '.')
        maxtl[i][j] = 0;
      else if (i == n-1 || j == m-1)
        maxtl[i][j] = 1;
      else
        maxtl[i][j] = min(min(maxtl[i+1][j], maxtl[i][j+1]), maxtl[i+1][j+1])+1;
  int l=1, r=n+1;
  while (r-l > 1) {
    int mid = (l+r)/2;
    bool covered = true;
    vector<vector<int>> diff(n+1, vector<int>(m+1, 0));
    for (int i=0; i<n; ++i)
      for (int j=0; j<m; ++j)
        if (maxtl[i][j] >= mid) {
          diff[i][j]++;
          diff[i][j+maxtl[i][j]]--;
          diff[i+maxtl[i][j]][j]--;
          diff[i+maxtl[i][j]][j+maxtl[i][j]]++;
        }
    vector<int> acum(m, 0);
    for (int i=0; i<n; ++i) {
      int d=0;
      for (int j=0; j<m; ++j) {
        d += diff[i][j];
        acum[j] += d;
        if (acum[j] == 0 && inp[i][j] == 'X')
          covered = false;
      }
    }
    if (covered)
      l = mid;
    else
      r = mid;
  }
  int t = (l-1)/2;
  vector<string> ans(n, string(m, '.'));
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
      if (maxtl[i][j] >= 2*t+1)
        ans[i+t][j+t] = 'X';
  cout << t << endl;
  for (string s : ans)
    cout << s << '\n';
}