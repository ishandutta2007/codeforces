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
    int n, q;
    cin >> n >> q;
    ll s0 = 0, s1 = 0;
    int c0 = 0, c1 = 0;
    rep(_, n) {
      int x;
      cin >> x;
      if (x % 2 == 0) {
        s0 += x;
        c0++;
      } else {
        s1 += x;
        c1++;
      }
    }
    while(q--) {
      int t, x;
      cin >> t >> x;
      if (t == 0) {
        s0 += (ll)c0 * x;
        if (x & 1) {
          s1 += s0;
          c1 += c0;
          s0 = 0;
          c0 = 0;
        }
      } else {
        s1 += (ll)c1 * x;
        if (x & 1) {
          s0 += s1;
          c0 += c1;
          s1 = 0;
          c1 = 0;
        }
      }
      cout << s0 + s1 << '\n';
    }
  }
}