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

int pre[150001];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  rep(i, 150001) pre[i] = -1;
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    int ans = -1;
    rep(i, n) {
      int x = a[i];
      if (pre[x] == -1) {
        pre[x] = i;
        continue;
      }
      int j = pre[x];
      chmax(ans, j + n - i);
      pre[x] = i;
    }
    for(int x : a) pre[x] = -1;
    cout << ans << '\n';
  }
}