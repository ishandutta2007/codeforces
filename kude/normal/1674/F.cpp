#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> m >> n >> q;
  vector<string> g(n, string(m, '.'));
  rep(j, m) rep(i, n) cin >> g[i][j];
  int icons = 0;
  rep(i, n) rep(j, m) icons += g[i][j] == '*';
  int gain = 0;
  rep(id, icons) gain += g[id / m][id % m] == '*';
  while(q--) {
    int i, j;
    cin >> j >> i;
    i--, j--;
    if (g[i][j] == '*') {
      g[i][j] = '.';
      if (i * m + j < icons) gain--;
      icons--;
      if (g[icons / m][icons % m] == '*') gain--;
    } else {
      g[i][j] = '*';
      if (i * m + j < icons) gain++;
      if (g[icons / m][icons % m] == '*') gain++;
      icons++;
    }
    cout << icons - gain << '\n';
  }
}