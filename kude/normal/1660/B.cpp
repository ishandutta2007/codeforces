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
    VI a(n);
    rep(i, n) cin >> a[i];
    if (n == 1) {
      cout << (a[0] == 1 ? "YES\n" : "NO\n");
    } else {
      auto it_mx1 = max_element(all(a));
      int mx1 = *it_mx1;
      a.erase(it_mx1);
      auto it_mx2 = max_element(all(a));
      int mx2 = *it_mx2;
      cout << (mx1 <= mx2 + 1 ? "YES\n" : "NO\n");
    }
  }
}