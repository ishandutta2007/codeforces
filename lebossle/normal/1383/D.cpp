#include <bits/stdc++.h>
using namespace std;

// This code uses the bossle/cp library
// Available at https://github.com/bossle/cp

/**** START OF LIBRARY CODE ****/

// #pragma STDC FENV_ACCESS OFF
// #pragma STDC FP_CONTRACT ON
// #pragma STDC CX_LIMITED_RANGE ON
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target ("avx2")

namespace cp_base {

auto init = (
  ios::sync_with_stdio(false),
  cin.tie(nullptr)
);

}  // namespace cp_base

typedef long long int lli;
typedef long double llf;

   /***********************\
   *                       *
   * ***     *****     *** *
   * ***  ***********  *** *
   *  *******************  *
   * *** ************* *** *
   *  ******* * * *******  *
   * *** ************* *** *
   * ***  *  *****  *  *** *
   *     **         **     *
   *     ***       ***     *
   *     ***       ***     *
   *     ***       ***     *
   *  ** ************* **  *
   * ********************* *
   * ********************* *
   *  ******* * * *******  *
   * ********************* *
   * ********************* *
   * ********************* *
   * ********************* *
   *     ** **   ** **     *
   * ***  * ******* *  *** *
   *                       *
   \***********************/

/**** END OF LIBRARY CODE ****/

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (auto& v : a)
    for (int& i : v)
      cin >> i;
  vector<int> rows(n), cols(m);
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j) {
      rows[i] = max(rows[i], a[i][j]);
      cols[j] = max(cols[j], a[i][j]);
    }
  sort(rows.begin(), rows.end(), greater<int>());
  sort(cols.begin(), cols.end(), greater<int>());
  vector<vector<int>> b(n, vector<int>(m));
  int x=0, y=0;
  vector<int> l(n), u(m);
  int lx=0, uy=0;
  for (int v=n*m; v>0; --v) {
    bool advX = (x<n && rows[x]==v);
    bool advY = (y<m && cols[y]==v);
    if (advX)
      x++;
    if (advY)
      y++;
    if (advX || advY) {
      b[x-1][y-1] = v;
      if (advX)
        l[x-1] = y-2;
      if (advY)
        u[y-1] = x-2;
    } else {
      while (lx < x && l[lx] == -1)
        lx++;
      while (uy < y && u[uy] == -1)
        uy++;
      if (lx < x) {
        b[lx][l[lx]] = v;
        l[lx]--;
      } else if (uy < y) {
        b[u[uy]][uy] = v;
        u[uy]--;
      } else {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
      cout << b[i][j] << (j==m-1 ? '\n' : ' ');
}