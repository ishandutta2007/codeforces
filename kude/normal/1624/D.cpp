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
    int hist[26] = {};
    int n, k;
    cin >> n >> k;
    rep(_, n) {
      char c;
      cin >> c;
      hist[c - 'a']++;
    }
    int c2 = 0, c1 = 0;
    rep(i, 26) {
      c2 += hist[i] / 2;
      c1 += hist[i] % 2;
    }
    int ans = c2 / k * 2;
    c2 %= k;
    c1 += 2 * c2;
    if (c1 >= k) ans++;
    cout << ans << '\n';
  }
}