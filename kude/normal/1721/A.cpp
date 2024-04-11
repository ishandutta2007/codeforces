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
    char c[4];
    rep(i, 4) cin >> c[i];
    sort(all(c));
    if (c[0] == c[3]) {
      cout << 0 << '\n';
    } else if (c[0] == c[2] || c[1] == c[3] || c[0] == c[1] && c[2] == c[3]) {
      cout << 1 << '\n';
    } else if (c[0] != c[1] && c[1] != c[2] && c[2] != c[3]) {
      cout << 3 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }
}