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
    string t;
    cin >> t;
    int m = t.size();
    VI to(m);
    VI sid(m);
    int n;
    cin >> n;
    rep(id, n) {
      string s;
      cin >> s;
      int slen = s.size();
      rep(i, m - slen + 1) if (t.substr(i, slen) == s) {
        if (chmax(to[i], i + slen)) sid[i] = id;
      }
    }
    vector<P> ans;
    bool ok = true;
    int i = 0;
    while(i != m) {
      int j = i;
      int pos = -1;
      rep(k, i + 1) if (chmax(j, to[k])) pos = k;
      if (j == i) {
        ok = false;
        break;
      }
      ans.emplace_back(sid[pos], pos);
      i = j;
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      int sz = ans.size();
      cout << sz << '\n';
      for(auto [id, pos]: ans) cout << id + 1 << ' ' << pos + 1 << '\n';
    }
  }
}