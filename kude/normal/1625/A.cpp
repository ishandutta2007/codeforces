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
    int n, l;
    cin >> n >> l;
    VI hist(l);
    rep(i, n) {
      int x;
      cin >> x;
      rep(j, l) hist[j] += x >> j & 1;
    }
    int ans = 0;
    rep(i, l) {
      int c1 = hist[i], c0 = n - c1;
      ans |= (c1 > c0) << i;
    }
    cout << ans << '\n';
  }
}