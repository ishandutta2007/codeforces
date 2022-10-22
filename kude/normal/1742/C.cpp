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
  int tt;
  cin >> tt;
  while(tt--) {
    int r[8][2]{}, c[8][2]{};
    rep(i, 8) rep(j, 8) {
      char cc;
      cin >> cc;
      int col = cc == 'B';
      r[i][col]++;
      c[j][col]++;
    }
    rep(i, 8) if (r[i][0] == 8) {
      cout << "R\n";
      break;
    }
    rep(j, 8) if (c[j][1] == 8) {
      cout << "B\n";
      break;
    }
  }
}