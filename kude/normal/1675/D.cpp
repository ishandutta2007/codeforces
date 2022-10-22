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
    VI p(n);
    vector<char> is_leaf(n, true);
    rep(i, n) {
      cin >> p[i];
      p[i]--;
      if (p[i] != i) is_leaf[p[i]] = false;
    }
    VVI ans;
    vector<char> done(n);
    rep(i, n) if (is_leaf[i]) {
      VI path;
      int v = i;
      while(!done[v]) {
        path.emplace_back(v);
        done[v] = true;
        if (v == p[v]) break;
        v = p[v];
      }
      reverse(all(path));
      ans.emplace_back(move(path));
    }
    int sz = ans.size();
    cout << sz << '\n';
    for(auto& a: ans) {
      int sz = a.size();
      cout << sz << '\n';
      rep(i, sz) cout << a[i] + 1 << " \n"[i + 1 == sz];
    }
  }
}