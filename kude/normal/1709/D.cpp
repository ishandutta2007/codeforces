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

template <class S, S (*op)(S, S)>
struct DisjointSparseTable {
  const int n;
  const vector<unsigned char> msb;
  const vector<vector<S>> d;
  DisjointSparseTable(vector<S> a) : n(a.size()), msb(build_msb_table(n)), d(build_table(move(a))) {}

  vector<unsigned char> build_msb_table(int n) {
    if (n <= 1) return {};
    unsigned char k_max = 32 - __builtin_clz(n - 1);
    vector<unsigned char> res(1 << k_max);
    unsigned char* p = res.data();
    for (unsigned char k = 0; k < k_max; k++) {
      memset(p + (1U << k), k, 1U << k);
    }
    return res;
  }
  vector<vector<S>> build_table(vector<S> a) {
    const int n = a.size();
    vector<vector<S>> res(1);
    if (n >= 2) {
      const int i_max = n - 1, k_max = 32 - __builtin_clz(i_max);
      res.resize(k_max);
      for (int k = 1; k < k_max; k++) {
        vector<S> t(i_max >> k & 1 ? n : i_max & ~0U << k);
        for (int c = 1 << k; c < n; c += 1 << (k + 1)) {
          int l = c - (1 << k);
          int r = min(n, c + (1 << k));
          t[c - 1] = a[c - 1];
          for (int i = c - 2; i >= l; i--) t[i] = op(a[i], t[i + 1]);
          t[c] = a[c];
          for (int i = c + 1; i < r; i++) t[i] = op(t[i - 1], a[i]);
        }
        res[k] = move(t);
      }
    }
    res[0] = move(a);
    return res;
  }

  S query(int l, int r) { return query_closed(l, r - 1); }
  S query_closed(int l, int r) {
    assert(0 <= l && l <= r && r < n);
    if (l == r) return d[0][l];
    auto k = msb[l ^ r];
    return op(d[k][l], d[k][r]);
  }
};

int op(int x, int y) { return max(x, y); }

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  // cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    VI a(m);
    rep(i, m) cin >> a[i];
    DisjointSparseTable<int, op> dst(move(a));
    int q;
    cin >> q;
    while(q--) {
      int si, sj, ti, tj, k;
      cin >> si >> sj >> ti >> tj >> k;
      si--, sj--, ti--, tj--;
      // r + kx <= n - 1
      // kx <= n - 1 - r
      si += (n - 1 - si) / k * k;
      ti += (n - 1 - ti) / k * k;
      if (si != ti || (sj - tj) % k) {
        cout << "NO\n";
        continue;
      }
      int mx = dst.query_closed(min(sj, tj), max(sj, tj));
      cout << (mx <= si ? "YES\n" : "NO\n");
    }
  }
}