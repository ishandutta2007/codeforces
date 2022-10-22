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
    priority_queue<ll, VL, greater<ll>> q;
    rep(i, n) {
      int a;
      cin >> a;
      q.push(a);
    }
    ll add = 0;
    ll ans = -1002003004005006007;
    while(q.size() > 1) {
      ll mn = q.top() + add; q.pop();
      chmax(ans, mn);
      add -= mn;
    }
    ll mn = q.top() + add;
    chmax(ans, mn);
    cout << ans << '\n';
  }
}