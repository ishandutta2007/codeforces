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

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  // cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    int now = 0;
    vector<P> st;
    rep(i, n) {
      st.emplace_back(0, i);
      int sz = st.size();
      rep(j, sz) st[j].first = gcd(st[j].first, a[i]);
      rep(j, sz - 1) if (st[j].first == st[j+1].first) {
        st[j+1].second = st[j].second;
      }
      st.erase(unique(all(st)), st.end());
      bool ok = true;
      rep(j, sz) {
        int l = st[j].second, r = j + 1 < sz ? st[j+1].second : i + 1;
        int g = st[j].first;
        int t = i + 1 - g;
        if (l <= t && t < r) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        st.clear();
        now++;
      }
      cout << now << " \n"[i + 1 == n];
    }
  }
}