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
    int x, y;
    cin >> x >> y;
    int z2 = x * x + y * y;
    if (z2 == 0) {
      cout << 0 << '\n';
      continue;
    }
    int zl = 0, zr = z2 + 1;
    while(zr - zl > 1) {
      int zc = (zl + zr) / 2;
      if (zc * zc <= z2) zl = zc;
      else zr = zc;
    }
    cout << (zl * zl == z2 ? 1 : 2) << '\n';
  }
}