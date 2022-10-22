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
    int q = n / 4, r = n % 4;
    if (r == 2) q--, r += 4;
    int ptr = 0;
    rep(i, q) {
      a[ptr++] = 16 + 4 * i + 0;
      a[ptr++] = 16 + 4 * i + 2;
      a[ptr++] = 16 + 4 * i + 1;
      a[ptr++] = 16 + 4 * i + 3;
    }
    if (r == 3) {
      a[ptr++] = 2;
      a[ptr++] = 1;
      a[ptr++] = 3;
    } else if (r == 6) {
      a[ptr++] = 4;
      a[ptr++] = 1;
      a[ptr++] = 2;
      a[ptr++] = 12;
      a[ptr++] = 3;
      a[ptr++] = 8;
    }
    rep(i, n) cout << a[i] << " \n"[i + 1 == n];
  }
}