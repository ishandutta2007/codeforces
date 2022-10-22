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
    VL a;
    int pos = 0, neg = 0, zero = 0;
    rep(i, n) {
      int x;
      cin >> x;
      if (x == 0) zero++;
      else {
        a.emplace_back(x);
        if (x > 0) pos++;
        else neg++;
      }
    }
    if (pos >= 3 || neg >= 3) {
      cout << "NO\n";
      continue;
    }
    chmin(zero, 3);
    a.insert(a.end(), zero, 0);
    n = a.size();
    bool ok = true;
    rep(i, n) rep(j, i) rep(k, j) {
      ll s = a[i] + a[j] + a[k];
      if (find(all(a), s) == a.end()) {
        ok = false;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}