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
    int n;
    cin >> n;
    VI p(n);
    rep(i, n) cin >> p[i], p[i]--;
    if (n == 1) {
      cout << -1 << '\n';
      continue;
    }
    VI avail(n);
    iota(rall(avail), 0);
    VI q(n);
    rep(i, n - 1) {
      if (p[i] != avail.back()) {
        q[i] = avail.back(); avail.pop_back();
      } else {
        swap(avail.end()[-1], avail.end()[-2]);
        q[i] = avail.back(); avail.pop_back();
      }
    }
    if (avail[1] != p[n - 2] && avail[0] != p[n - 1]) {
      q[n - 2] = avail[1];
      q[n - 1] = avail[0];
    } else {
      q[n - 2] = avail[0];
      q[n - 1] = avail[1];
    }
    rep(i, n) cout << q[i] + 1 << " \n"[i + 1 == n];
  }
}