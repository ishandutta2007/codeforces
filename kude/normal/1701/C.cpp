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
    int n, m;
    cin >> n >> m;
    VI d(n);
    rep(i, m) {
      int x;
      cin >> x;
      x--;
      d[x]++;
    }
    int l = -1, r = 2 * accumulate(all(d), 0);
    while(r - l > 1) {
      int c = (l + r) / 2;
      ll rest = 0;
      for(int x: d) {
        if (c >= x) {
          int t = c - x;
          rest -= t / 2;
        } else {
          rest += x - c;
        }
      }
      if (rest <= 0) r = c;
      else l = c;
    }
    cout << r << '\n';
  }
}