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
    int n, q;
    cin >> n >> q;
    VI a(n + 1);
    rep(i, n) cin >> a[i];
    a[n] = -1;
    n++;
    set<int> st;
    constexpr int INF = 1001001001;
    int mn = INF;
    rep(i, n) if (a[i] < mn) {
      st.emplace(i);
      mn = a[i];
    }
    rep(i, q) {
      int k, d;
      cin >> k >> d;
      if (d) {
        k--;
        a[k] -= d;
        auto it = prev(st.upper_bound(k));
        if (*it == k || a[*it] > a[k]) {
          it = st.emplace_hint(it, k);
          it++;
          while(a[k] <= a[*it]) it = st.erase(it);
        }
      }
      cout << (int)st.size() - 1 << " \n"[i + 1 == q];
    }
  }
}