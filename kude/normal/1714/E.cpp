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
    int st = 0;
    for(int& x: a) {
      while(x % 10 != 0 && x % 10 != 2) x += x % 10;
      st |= 1 << (x % 10 / 2);
    }
    if (st == 3) {
      cout << "NO\n";
    } else if (st == 1) {
      cout << (*min_element(all(a)) == *max_element(all(a)) ? "YES\n" : "NO\n");
    } else {
      st = 0;
      for(int x: a) st |= 1 << (x / 10 % 2);
      cout << (st != 3 ? "YES\n" : "NO\n");
    }
  }
}