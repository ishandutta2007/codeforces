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
    VI b(n);
    rep(i, n) cin >> b[i];
    swap(a, b);
    map<int, int> del_reserve;
    int j = n - 1;
    bool ok = true;
    for(int i = n - 1; i >= 0;) {
      int l = i - 1;
      while(l >= 0 && a[l] == a[i]) l--;
      int x = a[i];
      int cnt = i - l;
      while(b[j] != x) {
        if (--del_reserve[b[j]] < 0) {
          ok = false;
          break;
        }
        j--;
      }
      if (!ok) break;
      j--;
      del_reserve[x] += cnt - 1;
      i = l;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}