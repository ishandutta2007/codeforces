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
    VL a(n);
    rep(i, n) cin >> a[i];
    ll x = accumulate(all(a), 0LL);
    priority_queue<ll> q1, q2;
    rep(i, n) q1.emplace(a[i]);
    q2.emplace(x);
    bool ok = true;
    while(q1.size()) {
      ll x = q2.top(); q2.pop();
      if (x == q1.top()) {
        q1.pop();
      } else if (x < q1.top()) {
        ok = false;
        break;
      } else {
        q2.emplace(x / 2);
        q2.emplace((x + 1) / 2);
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}