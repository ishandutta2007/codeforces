#line 2 "/home/maspy/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ll8 = __int128;
using ld = long double;
using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using vvvvvc = vector<vvvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))
#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))
#define FORIN(x, A) for (auto&& x : A)
#define FOR_nCk(s, n, k) \
  for (ll s = (1 << k) - 1, tmp_var = 0; s < (1 << n); \
  tmp_var = s | (s - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctz(s) + 1))) 
#define FOR_SUB(t, s) for(ll t = s; t >= 0; t = (t==0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())

#define elif else if

using ull = unsigned long long;
using uint = unsigned int;
int popcnt(uint x) {
  return __builtin_popcount(x);
}
int popcnt(int x) {
  return __builtin_popcount(x);
}
int popcnt(ull x) {
  return __builtin_popcountll(x);
}
int popcnt(ll x) {
  return __builtin_popcountll(x);
}
int bsr(uint x) {
  return 31 - __builtin_clz(x);
}
int bsr(ull x) {
  return 63 - __builtin_clzll(x);
}
int ctz(int x) {
  return __builtin_ctz(x);
}
int ctz(ll x) {
  return __builtin_ctzll(x);
}
int ctz(ull x) {
  return __builtin_ctzll(x);
}

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

ll ceil(ll x, ll y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

ll floor(ll x, ll y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

ll mod(ll x, ll y) {
  return x - y * floor(x, y);
}

#define INT(...) \
  int __VA_ARGS__; \
  IN(__VA_ARGS__)
#define LL(...) \
  ll __VA_ARGS__; \
  IN(__VA_ARGS__)
#define STR(...) \
  string __VA_ARGS__; \
  IN(__VA_ARGS__)
#define CHR(...) \
  char __VA_ARGS__; \
  IN(__VA_ARGS__)
#define DBL(...) \
  long double __VA_ARGS__; \
  IN(__VA_ARGS__)
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &a) {for(auto &i : a) scan(i);}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
  scan(head);
  IN(tail...);
}

ll isqrt(ll n) {
  ll x = n, y = (n + 1) / 2;
  while (y < x) { tie(x, y) = mp(y, (y + n / y) / 2); }
  return x;
}

vi s_to_vi(string S, char first_char='a'){
  vi A(S.size());
  FOR(i, S.size()){
    A[i] = S[i] - first_char;
  }
  return A;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}

void print() {
  cout << "\n";
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }

template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vi bin_count(vi& A, ll size) {
  vi C(size);
  for (auto&& x : A) {
    ++C[x];
  }
  return C;
}

template <typename T>
vi argsort(vector<T>& A){
  vi ids(A.size());
  iota(all(ids), 0);
  sort(all(ids), [&](ll i, ll j){
    return A[i] < A[j] || (A[i] == A[j] && i < j);
  });
  return ids;
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }

template <typename T>
vc<T> merge_sort(vc<T>& A, vc<T>& B) {
  vc<T> C;
  C.reserve(A.size() + B.size());
  merge(all(A), all(B), back_inserter(C));
  return C;
}
#line 2 "main.cpp"

#line 1 "/home/maspy/library/ds/fastset.hpp"
struct FastSet {
  using uint = unsigned;
  using ull = unsigned long long;

  int bsr(ull x) { return 63 - __builtin_clzll(x); }
  int bsf(ull x) { return __builtin_ctzll(x); }

  static constexpr uint B = 64;
  int n, lg;
  vc<vc<ull>> seg;
  FastSet(int _n) : n(_n) {
    do {
      seg.push_back(vc<ull>((_n + B - 1) / B));
      _n = (_n + B - 1) / B;
    } while (_n > 1);
    lg = int(seg.size());
  }
  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }
  void insert(int i) {
    for (int h = 0; h < lg; h++) {
      seg[h][i / B] |= 1ULL << (i % B);
      i /= B;
    }
  }
  void erase(int i) {
    for (int h = 0; h < lg; h++) {
      seg[h][i / B] &= ~(1ULL << (i % B));
      if (seg[h][i / B])
        break;
      i /= B;
    }
  }
  // x
  int next(int i) {
    for (int h = 0; h < lg; h++) {
      if (i / B == seg[h].size())
        break;
      ull d = seg[h][i / B] >> (i % B);
      if (!d) {
        i = i / B + 1;
        continue;
      }
      // find
      i += bsf(d);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += bsf(seg[g][i / B]);
      }
      return i;
    }
    return n;
  }
  // x
  int prev(int i) {
    if(i < 0) return -1;
    chmin(i, n - 1);
    for (int h = 0; h < lg; h++) {
      if (i == -1)
        break;
      ull d = seg[h][i / B] << (63 - i % 64);
      if (!d) {
        i = i / B - 1;
        continue;
      }
      // find
      i += bsr(d) - (B - 1);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += bsr(seg[g][i / B]);
      }
      return i;
    }
    return -1;
  }
  void print(){
    for(int i=0;i<n;++i) cout << (*this)[i];
    cout << endl;
  }
};
#line 2 "/home/maspy/library/ds/fenwick.hpp"
template <typename T> struct FenwickTree {
  vector<T> data;
  T total;

  FenwickTree(int sz) : total(0) { data.assign(++sz, 0); }

  void build(vector<T> &raw_data) {
    assert(len(data) == len(raw_data) + 1);
    FOR(i, len(raw_data)) data[i + 1] = raw_data[i];
    FOR(i, len(data)) {
      int j = i + (i & -i);
      if (j < len(data))
        data[j] += data[i];
    }
  }

  T sum(int k) {
    T ret = 0;
    for (; k > 0; k -= k & -k)
      ret += data[k];
    return (ret);
  }

  T sum(int L, int R) { return sum(R) - sum(L); }

  T sum_all() { return total; }

  void add(int k, T x) {
    total += x;
    for (++k; k < data.size(); k += k & -k)
      data[k] += x;
  }

  ll find_kth_element(T k) {
    auto N = data.size();
    ll x = 0;
    T sx = 0;
    ll dx = 1;
    while (2 * dx < N)
      dx *= 2;
    while (dx) {
      ll y = x + dx;
      if (y < N) {
        T sy = sx + data[y];
        if (sy < k) {
          swap(x, y);
          swap(sx, sy);
        }
      }
      dx /= 2;
    }
    return x;
  }
};

template <typename T> struct Fenwick_RAQ {
  int N;
  FenwickTree<T> bit0;
  FenwickTree<T> bit1;

  Fenwick_RAQ(int N) : N(N), bit0(N), bit1(N) {}

  void add(ll L, ll R, T val) {
    bit0.add(L, -val * L);
    bit1.add(L, +val);
    bit0.add(R, +val * R);
    bit1.add(R, -val);
  }

  T sum(ll L, ll R) {
    T sum_R = R * bit1.sum(R) + bit0.sum(R);
    T sum_L = L * bit1.sum(L) + bit0.sum(L);
    return sum_R - sum_L;
  }
};
#line 3 "/home/maspy/library/ds/unionfind.hpp"

struct UnionFind {
  int num;
  int comp;
  vi size, par;
  UnionFind(int n) : num(n), comp(n), size(n, 1), par(n) { iota(par.begin(), par.end(), 0); }
  int find(int x) {
    while (par[x] != x) {
      par[x] = par[par[x]];
      x = par[x];
    }
    return x;
  }

  int operator[](int x) {
    return find(x);
  }


  bool merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    comp--;
    if (size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    size[y] = 0;
    par[y] = x;
    return true;
  }

  vi find_all() {
    vi A(num);
    FOR(i, num) A[i] = find(i);
    return A;
  }
};
#line 6 "main.cpp"

using P = pair<ll, ll>;
using PP = pair<P, P>;
void solve() {
  LL(N);
  vc<PP> segment(N);
  vi X, Y;
  FOR(i, N) {
    LL(a, b, c, d);
    X.eb(a);
    X.eb(c);
    Y.eb(b);
    Y.eb(d);
    if (a + b > c + d) {
      swap(a, c);
      swap(b, d);
    }
    segment[i] = {{a, b}, {c, d}};
  }
  UNIQUE(X);
  UNIQUE(Y);
  FOR(i, N) {
    auto [A, B] = segment[i];
    A.fi = LB(X, A.fi);
    A.se = LB(Y, A.se);
    B.fi = LB(X, B.fi);
    B.se = LB(Y, B.se);
    segment[i] = {A, B};
  }

  vc<vi> begin_seg(len(X));
  vc<vi> end_seg(len(X));
  vc<vi> segX(len(X));
  FOR(i, N) {
    auto [A, B] = segment[i];
    if (A.fi == B.fi)
      segX[A.fi].eb(i);
    else {
      begin_seg[A.fi].eb(i);
      end_seg[B.fi].eb(i);
    }
  }

  UnionFind uf(N);
  vi CNT(N);
  FastSet ss(len(Y));
  FastSet ss_union(len(Y));
  FenwickTree<ll> bit(len(Y));
  vi to_i(len(Y), -1);

  FOR(x, len(X)) {
    FORIN(i, begin_seg[x]) {
      auto y = segment[i].fi.se;
      ss.insert(y);
      bit.add(y, 1);
      to_i[y] = i;

      auto yl = ss.prev(y - 1);
      auto yr = ss.next(y + 1);
      if (yl >= 0) ss_union.insert(yl);
      if (yr < len(Y)) ss_union.insert(y);
    }
    FORIN(i, segX[x]) {
      auto yl = segment[i].fi.se;
      auto yr = segment[i].se.se;
      CNT[i] = bit.sum(yl, yr + 1);
      auto y = ss.next(yl);
      if (y <= yr) uf.merge(i, to_i[y]);
      while (1) {
        auto y1 = ss_union.next(yl);
        if (y1 > yr) break;
        auto y2 = ss.next(y1 + 1);
        if (y2 > yr) break;
        uf.merge(to_i[y1], to_i[y2]);
        ss_union.erase(y1);
      }
    }
    FORIN(i, end_seg[x]) {
      auto y = segment[i].fi.se;
      ss.erase(y);
      bit.add(y, -1);
      to_i[y] = -1;

      auto yl = ss.prev(y - 1);
      auto yr = ss.next(y + 1);
      if (yl >= 0) ss_union.insert(yl);
      ss_union.erase(y);
    }
  }
  // print("CNT", CNT);
  // print("comp", uf.find_all());

  vi V(N);
  FOR(i, N) {
    auto [A, B] = segment[i];
    ll dx = X[B.fi] - X[A.fi];
    ll dy = Y[B.se] - Y[A.se];
    V[uf[i]] += dx + dy + 1;
    V[uf[i]] -= CNT[i];
  }
  ll ANS = MAX(V) - 1;
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  // LL(T);
  ll T = 1;
  FOR(_, T) solve();

  return 0;
}