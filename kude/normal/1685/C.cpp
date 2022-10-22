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
    n *= 2;
    string s;
    cin >> s;
    VI a(n + 1);
    rep(i, n) a[i+1] = a[i] + (s[i] == '(' ? 1 : -1);
    if (*min_element(all(a)) == 0) {
      cout << 0 << '\n';
      continue;
    }
    {
      int i = 0, j = n;
      int lmx = 0, rmx = 0;
      int ilmx = 0, irmx = n;
      while(a[i+1] >= 0) {
        i++;
        if (chmax(lmx, a[i])) ilmx = i;
      }
      while(a[j-1] >= 0) {
        j--;
        if (chmax(rmx, a[j])) irmx = j;
      }
      reverse(s.begin() + ilmx, s.begin() + irmx);
      bool ok = true;
      int now = 0;
      for(char c: s) {
        if (c == '(') now++;
        else now--;
        if (now < 0) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << 1 << '\n';
        cout << ilmx + 1 << ' ' << irmx << '\n';
        continue;
      }
      reverse(s.begin() + ilmx, s.begin() + irmx);
    }
    auto imx = max_element(all(a)) - a.begin();
    cout << 2 << '\n';
    cout << 1 << ' ' << imx << '\n';
    cout << imx + 1 << ' ' << n << '\n';
  }

}