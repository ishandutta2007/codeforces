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

template <class S, S (*op)(S, S), S (*e)()> struct SparseTable {
    int n;
    std::vector<int> floor_lg;
    std::vector<std::vector<S>> d;
    explicit SparseTable(std::vector<S>&& a): n(a.size()), floor_lg(n + 1) {
        if (n == 0) return;
        int frog = 0;
        for(int i = 1; i <= n; frog++) {
            int j = std::min(n + 1, 2 * i);
            for(; i < j; i++) floor_lg[i] = frog;
        }
        d.resize(frog);
        d[0] = std::move(a);
        for(int p = 0, w = 1; p < frog - 1; p++, w *= 2) {
            int last = n - 2 * w;
            d[p + 1].resize(last + 1);
            for(int i = 0; i <= last; i++) d[p + 1][i] = op(d[p][i], d[p][i + w]);
        }
    }
    explicit SparseTable(const std::vector<S>& a): SparseTable(std::vector<S>(a)) {}

    S query(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        if (l >= r) return e();
        int w = r - l;
        int p = floor_lg[w];
        return op(d[p][l], d[p][r - (1 << p)]);
    }
};

ll op(ll x, ll y) { return min(x, y); }
ll e() { return -1002003004005006007LL; }

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, ss;
    cin >> n >> ss;
    VL a(n);
    rep(i, n) cin >> a[i];
    VL s(n + 1);
    rep(i, n) s[i + 1] = s[i] + a[i];
    SparseTable<ll, op, e> st(s);
    int mx = 0;
    int lmx = -1, rmx = -1;
    rep(i, n) {
      int l = i, r = n + 1;
      ll ub = s[i] - ss;
      while(r - l > 1) {
        int c = (l + r) / 2;
        if (st.query(i, c + 1) >= ub) l = c;
        else r = c;
      }
      if (l - i > mx) {
        mx = l - i;
        lmx = i;
        rmx = l;
      }
    }
    if (mx == 0) {
      cout << -1 << '\n';
    } else {
      cout << lmx + 1 << ' ' << rmx << '\n';
    }
    // VI st{n};
    // VVI to(20, VI(n + 1));
    // to[0][n] = -1;
    // rrep(i, n) {
    //   while(s[st.back()] >= s[i]) st.pop_back();
    //   to[0][i] = st.back();
    //   st.push_back(i);
    // }
    // rep(k, 19) {
    //   rep(i, n) {
    //     if (to[k][i] == -1) to[k + 1][i] = -1;
    //     else to[k + 1][i] = to[k][to[k][i]];
    //   }
    // }
    // int mx = -1;
    // int lmx = -1, rmx = -1;
    // rep(i, n) {
    //   ll ub = s[i] - s;
    //   int v = i;
    //   rrep(k, 20) if (to[k][v] != -1) {
    //     if (s[to[k][v]] >= ub) v = to[k][v];
    //   }
    //   if (i != v && v - i > mx) {
    //     mx = v - i;
    //     lmx = i;
    //     rmx = v;
    //   }
    // }
    // if (mx )
  }
}