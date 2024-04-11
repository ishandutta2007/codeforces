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
    int n, k;
    cin >> n >> k;
    VL s(k);
    rep(i, k) cin >> s[i];
    if (k == 1) {
      cout << "Yes\n";
      continue;
    }
    bool ok = true;
    ll d = s[k-1] - s[k-2];
    rrep(i, k - 2) {
      ll d1 = s[i+1] - s[i];
      if (d1 > d) {
        ok = false;
        break;
      }
      d = d1;
    }
    if (!ok) {
      cout << "No\n";
      continue;
    }
    ll p = s[0] - (n-k+1) * d;
    if (p > 0) ok = false;
    cout << (ok ? "Yes\n" : "No\n");
  }
}