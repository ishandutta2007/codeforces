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
    int n, m;
    cin >> n >> m;
    priority_queue<int> q;
    VI ans(n * m);
    rep(i, n) rep(j, m) {
      int mx = 0;
      for(int x : {0, n - 1}) {
        for(int y : {0, m - 1}) {
          chmax(mx, abs(x - i) + abs(y - j));
        }
      }
      ans[i * m + j] = mx;
    }
    sort(all(ans));
    rep(i, n * m) cout << ans[i] << " \n"[i + 1 == n * m];
  }
}