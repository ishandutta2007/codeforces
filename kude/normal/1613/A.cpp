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
    ll x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    int t = min(p1, p2);
    p1 -= t, p2 -= t;
    if (p1 >= 7) {
      cout << '>' << '\n';
      continue;
    }
    if (p2 >= 7) {
      cout << '<' << '\n';
      continue;
    }
    rep(_, p1) x1 *= 10;
    rep(_, p2) x2 *= 10;
    cout << (x1 < x2 ? '<' : x1 > x2 ? '>' : '=') << '\n';
  }
}