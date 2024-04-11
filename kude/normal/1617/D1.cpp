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

int ask(int a, int b, int c) {
  cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
  int res;
  cin >> res;
  return res;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    VI d(n / 3);
    rep(i, n / 3) {
      int a = 3 * i, b = a + 1, c = b + 1;
      int res = ask(a, b, c);
      d[i] = res;
    }
    int bp = 0;
    int wp = 0;
    while(d[bp] == 1) bp++;
    while(d[wp] == 0) wp++;
    // cout << bp << wp << endl;
    int b = -1, w = -1;
    // rep(x, 2) rep(y, 2) {
    //   int x1 = (x + 1) % 3, x2 = (x + 2) % 3;
    //   if (ask(3 * bp + x1, 3 * bp + x2, 3 * wp + y) == 1) {
    //     b = x;
    //     w = 3 * wp + y;
    //   }
    // }
    if (ask(3 * bp, 3 * bp + 1, 3 * wp) == 1) {
      w = 3 * wp;
      b = 3 * bp + 2;
    } else if (ask(3 * bp + 1, 3 * bp + 2, 3 * wp) == 1) {
      w = 3 * wp;
      b = 3 * bp;
    } else if (ask(3 * bp, 3 * bp + 1, 3 * wp + 1) == 1) {
      w = 3 * wp + 1;
      b = 3 * bp + 2;
    } else if (ask(3 * bp + 1, 3 * bp + 2, 3 * wp + 1) == 1) {
      w = 3 * wp + 1;
      b = 3 * bp;
    } else {
      b = 3 * bp;
      if (ask(b, 3 * wp, 3 * wp + 1) == 1) {
        w = 3 * wp;
      } else {
        w = 3 * wp + 2;
      }
    }
    // cout << b << ' ' << w << endl;
    vector<char> s(n);
    rep(i, n / 3) {
      int i0 = 3 * i, i1 = i0 + 1, i2 = i1 + 1;
      if (d[i] == 0) {
        if (i0 != w && i1 != w && ask(i0, i1, w) == 0) {
          s[i0] = s[i1] = 0;
          s[i2] = ask(i2, b, w);
        } else {
          s[i2] = 0;
          if (i0 == b || (i0 != w && ask(i0, b, w) == 0)) {
            s[i0] = 0;
            s[i1] = 1;
          } else {
            s[i0] = 1;
            s[i1] = 0;
          }
        }
      } else {
        if (i0 == b || i1 == b || ask(i0, i1, b) == 1) {
          s[i0] = s[i1] = 1;
          s[i2] = ask(i2, b, w);
        } else {
          s[i2] = 1;
          if (i0 == b || (i0 != w && ask(i0, b, w) == 0)) {
            s[i0] = 0;
            s[i1] = 1;
          } else {
            s[i0] = 1;
            s[i1] = 0;
          }
        }
      }
    }
    vector<int> ans;
    rep(i, n) if (s[i] == 0) ans.push_back(i);
    int k = ans.size();
    cout << "! " << k;
    rep(i, k) cout << ' ' << ans[i] + 1;
    cout << endl;
  }
}