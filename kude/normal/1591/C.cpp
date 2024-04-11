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
    int n, k;
    cin >> n >> k;
    VI x1, x2;
    rep(i, n) {
      int xi;
      cin >> xi;
      if (xi > 0) x1.push_back(xi);
      else if (xi < 0) x2.push_back(-xi);
    }
    sort(all(x1));
    sort(all(x2));
    ll ans = 1002003004005006007;
    rep(_, 2) {
      ll d = 0;
      int n1 = x1.size(), n2 = x2.size();
      for(int i = n1 - 1 - k; i >= 0; i -= k) {
        d += 2 * x1[i];
      }
      for(int i = n2 - 1; i >= 0; i -= k) {
        d += 2 * x2[i];
      }
      if (x1.size()) d += x1.back();
      chmin(ans, d);
      swap(x1, x2);
    }
    cout << ans << '\n';
  }
}