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

struct S {
  array<char, 3> a, b;
  int cnt;
};

S op(S x, S y) {

  // cout << x.cnt << ' ' << y.cnt << '\n';
  // rep(j, 3) cout << x.a[j] << x.b[j] << y.a[j] << y.b[j] << '\n';

  rep(i, 3) if (y.a[i]) y.a[i] += 6;
  rep(i, 3) if (y.b[i]) y.b[i] += 6;
  int cnt = x.cnt + y.cnt;
  if (x.b[0] && x.b[2] && x.b[0] != x.b[2] && y.a[0] && y.a[0] == y.a[2]) {
    cnt -= 2;
    int ncol = x.b[0];
    int pcol = x.b[2];
    rep(i, 3) if (x.a[i] == pcol) x.a[i] = ncol;
    // rep(i, 3) if (x.b[i] == pcol) x.b[i] = ncol;
    pcol = y.a[0];
    // rep(i, 3) if (y.a[i] == pcol) y.a[i] = ncol;
    rep(i, 3) if (y.b[i] == pcol) y.b[i] = ncol;
  } else {
    rep(i, 3) if (x.b[i] && y.a[i] && x.b[i] != y.a[i]) {
      cnt--;
      int pcol = y.a[i];
      int ncol = x.b[i];
      rep(i, 3) if (y.a[i] == pcol) y.a[i] = ncol;
      rep(i, 3) if (y.b[i] == pcol) y.b[i] = ncol;
    }
  }
  S res{x.a, y.b, cnt};
  int id[13];
  memset(id, -1, sizeof(id));
  int nxt = 1;
  rep(i, 3) if (res.a[i]) {
    int c = res.a[i];
    if (id[c] == -1) {
      res.a[i] = id[c] = nxt++;
    } else {
      res.a[i] = id[c];
    }
  }
  rep(i, 3) if (res.b[i]) {
    int c = res.b[i];
    if (id[c] == -1) {
      res.b[i] = id[c] = nxt++;
    } else {
      res.b[i] = id[c];
    }
  }
  
  // cout << res.cnt << '\n';
  // rep(j, 3) cout << res.a[j] << res.b[j] << '\n';

  return res;
}

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


} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s[3];
  rep(i, 3) cin >> s[i];
  vector<S> d(n);
  rep(i, n) {
    array<char, 3> a;
    rep(j, 3) a[j] = s[j][i] - '0';
    if (a[0] == 1 && a[1] == 0 && a[2] == 1) {
      a[2] = 2;
      d[i] = {a, a, 2};
    } else {
      int cnt = 0;
      rep(i, 3) if (a[i]) {
        cnt = 1;
        break;
      }
      d[i] = {a, a, cnt};
    }
  }
  DisjointSparseTable<S, op> st(move(d));
  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    l--;
    // cout << "query start\n";
    int res = st.query(l, r).cnt;
    // cout << "query end\n";
    // {
    //   auto s = st.query(l, r);
    //   rep(i, 3) cout << s.a[i] << " \n"[i == 2];
    //   rep(i, 3) cout << s.b[i] << " \n"[i == 2];
    // }
    cout << res << '\n';
  }
}