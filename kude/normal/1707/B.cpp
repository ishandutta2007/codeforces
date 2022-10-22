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
    VI a; a.reserve(n);
    int zcnt = 0;
    rep(i, n) {
      int x;
      cin >> x;
      if (x == 0) zcnt++;
      else a.emplace_back(x);
    }
    VI b;
    rep(i, n - 1) {
      int nz = 0;
      b.clear();
      if (zcnt) {
        nz = zcnt - 1;
        int pre = 0;
        for(int x: a) {
          int v = x - pre;
          if (v == 0) nz++;
          else b.emplace_back(v);
          pre = x;
        }
      } else {
        rep(i, (int)a.size() - 1) {
          int v = a[i + 1] - a[i];
          if (v == 0) nz++;
          else b.emplace_back(v);
        }
      }
      sort(all(b));
      swap(a, b);
      swap(zcnt, nz);
    }
    if (a.empty()) cout << 0 << '\n';
    else cout << a[0] << '\n';
  }
}