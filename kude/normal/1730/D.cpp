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
    string s1, s2;
    cin >> s1 >> s2;
    VI d, e;
    rep(i, n) {
      if (s1[i] != s2[n - 1 - i]) {
        int s = 1 << (s1[i] - 'a') | 1 << (s2[n - 1 - i] - 'a');
        d.emplace_back(s);
      } else {
        e.emplace_back(s1[i] - 'a');
      }
    }
    sort(all(d));
    bool ok = true;
    int sz = d.size();
    if (sz % 2) ok = false;
    if (ok) {
      sort(all(d));
      rep(i, sz / 2) if (d[2 * i] != d[2 * i + 1]) {
        ok = false;
      }
    }
    if (ok) {
      int sz = e.size();
      sort(all(e));
      int cnt = 0;
      for(int i = 0; i < sz;) {
        int j = i + 1;
        while(j < sz && e[i] == e[j]) j++;
        cnt += (j - i) % 2;
        i = j;
      }
      if (cnt >= 2) {
        ok = false;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}