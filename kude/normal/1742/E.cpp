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
    VI a(n);
    rep(i, n) cin >> a[i];
    priority_queue<P, vector<P>, greater<P>> que;
    rep(i, q) {
      int k;
      cin >> k;
      que.emplace(k, i);
    }
    ll now = 0;
    VL ans(q);
    for(int x: a) {
      while(!que.empty() && que.top().first < x) {
        ans[que.top().second] = now;
        que.pop();
      }
      now += x;
    }
    while(!que.empty()) {
      ans[que.top().second] = now;
      que.pop();
    }
    rep(i, q) cout << ans[i] << " \n"[i + 1 == q];
  }
}