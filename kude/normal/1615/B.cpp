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

int cnt[200011][20];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  rep(i, 200010) {
    rep(k, 20) cnt[i + 1][k] = cnt[i][k] + (i >> k & 1);
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int l, r;
    cin >> l >> r;
    r++;
    int ans = 0;
    rep(k, 20) chmax(ans, cnt[r][k] - cnt[l][k]);
    cout << (r - l - ans) << '\n';
  }
}