#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
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
    VVI d(n, VI(n));
    rep(i, n) rep(j, n) cin >> d[i][j];
    int ans = 0;
    rep(_, 2) {
      for(int s = 0; s <= (n - 1) * 2; s += 4) {
        int i = 0, j = s;
        if (j >= n) {
          int diff = j - (n - 1);
          i += diff;
          j -= diff;
        }
        for(; i < n; i += 2, j -= 2) {
          if (0 <= j && j < n) {
            ans ^= d[i][j];
          }
        }
      }
      rep(i, n) reverse(all(d[i]));
    }
      

    cout << ans << '\n';
  }
}