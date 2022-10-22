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
    int n, k;
    cin >> n >> k;
    map<int, P> mp;
    rep(i, n) {
      int u;
      cin >> u;
      auto it = mp.find(u);
      if (it == mp.end()) mp.emplace(u, P{i, i});
      else it->second.second = i;
    }
    rep(_, k) {
      int a, b;
      cin >> a >> b;
      auto ita = mp.find(a);
      auto itb = mp.find(b);
      if (ita == mp.end() || itb == mp.end()) {
        cout << "NO\n";
        continue;
      }
      cout << (ita->second.first <= itb->second.second ? "YES\n" : "NO\n");
    }
  }
}