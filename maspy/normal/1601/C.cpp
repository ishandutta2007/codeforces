#line 2 "/home/maspy/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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

#define elif else if

#define popcnt_int __builtin_popcount
#define popcnt __builtin_popcountll

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

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
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

#line 3 "/home/maspy/library/ds/fenwick.hpp"

template< typename T >
struct FenwickTree {
  vector< T > data;
  T total;

  FenwickTree(int sz) :total (0){
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  T sum_all() {
    return total;
  }

  void add(int k, T x) {
    total += x;
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }

  ll find_kth_element(T k){
    auto N = data.size();
    ll x = 0;
    T sx = 0;
    ll dx = 1;
    while (2 * dx < N) dx *= 2;
    while(dx){
      ll y = x + dx;
      if(y<N){
        T sy = sx + data[y];
        if(sy < k){
          swap(x, y);
          swap(sx, sy);
        }
      }
      dx /= 2;
    }
    return x;
  }
};
#line 3 "/home/maspy/library/ds/segtree.hpp"

template <typename T>
struct SegTree{
  using F = function<T(T,T)>;
  int N_;
  int N;
  F seg_f;
  T T_unit;
  vector<T> dat;

  SegTree(F f,T T_unit): seg_f(f), T_unit(T_unit) {}
  
  void init(int n_){
    N_ = n_;
    N=1;
    while(N<n_) N<<=1;
    dat.assign(N<<1,T_unit);
  }

  void build(const vector<T> &v){
    init(v.size());
    FOR(i, v.size()) dat[N + i] = v[i];
    FOR3_R(i, 1, N){
      dat[i] = seg_f(dat[i<<1 | 0], dat[i<<1 | 1]);
    }
  }

  void set(int i, T x){
    assert(i < N_);
    dat[i += N] = x;
    while(i >>= 1){
      dat[i] = seg_f(dat[i<<1 | 0],dat[i<<1 | 1]);
    }
  }

  T fold(int L, int R){
    assert(L <= R);
    T vl = T_unit, vr = T_unit;
    L += N;
    R += N;
    while(L < R){
      if(L & 1) vl = seg_f(vl, dat[L++]);
      if(R & 1) vr = seg_f(dat[--R], vr);
      L >>= 1;
      R >>= 1;
    }
    return seg_f(vl, vr);
  }
  
  template<typename C>
  int max_right(int s,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=seg_f(acc,dat[k]);
      return check(acc)?-1:k-N;
    }
    int m=(l+r)>>1;
    if(m<=s) return max_right(s,check,acc,(k<<1)|1,m,r);
    if(s<=l and check(seg_f(acc,dat[k]))){
      acc=seg_f(acc,dat[k]);
      return -1;
    }
    int vl=max_right(s,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return max_right(s,check,acc,(k<<1)|1,m,r);
  }

  // max t s.t. check(query(s,t))
  // O(\log N)
  template<typename C>
  int max_right(int s,C &check){
    assert(s<N and check(T_unit));
    if(check(fold(s, N_))) return N_;
    T acc=T_unit;
    return max_right(s,check,acc,1,0,N);
  }
};
#line 5 "main.cpp"

template <typename T>
ll inversion(vc<T> A) {
  auto key = A;
  UNIQUE(key);
  FORIN(x, A) x = LB(key, x);
  ll N = key.size();
  ll ANS = 0;
  FenwickTree<ll> bit(N);
  ll inv = A.size() * (A.size() - 1) / 2;
  FOR(i, A.size()) {
    ll x = A[i];
    ANS += i - bit.sum(x + 1);
    bit.add(x, 1);
  }
  return ANS;
}

void solve() {
  LL(N, M);
  VEC(ll, A, N);
  VEC(ll, B, M);
  vi key = A;
  key.insert(key.end(), all(B));
  UNIQUE(key);
  FORIN(x, A) x = LB(key, x);
  FORIN(x, B) x = LB(key, x);

  ll inv_A = inversion(A);
  ll lim = key.size();

  vc<vi> IA(lim);
  FOR(i, N) IA[A[i]].eb(i);

  auto CNT_B = bin_count(B, lim);
  const int INF = 1 << 30;

  using E = pair<int, int>;

  // pair of (total sum, prefix minimum)
  SegTree<E> seg(
    [](E x, E y) {
      if (x.se == INF) return y;
      if (y.se == INF) return x;
      return mp(x.fi + y.fi, min(x.fi + y.se, x.se));
    },
    mp(0, INF));

  seg.init(N);
  vc<E> seg_raw(N);
  FOR(p, N) seg_raw[p] = mp(1, 0);
  seg.build(seg_raw);

  ll small = 0, large = N;
  ll inv_AB = 0;

  FOR(v, lim) {
    ll coef = CNT_B[v];
    FORIN(i, IA[v]) {
      --large;
      seg.set(i, mp(0, 0));
    }
    auto x = seg.fold(0, N);
    // print(small, x);
    inv_AB += coef * (small + x.se);
    FORIN(i, IA[v]) {
      ++small;
      seg.set(i, mp(-1, -1));
    }
  }
  ll ANS = inv_A + inv_AB;
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  LL(T);
  FOR(_, T) solve();

  // solve();

  return 0;
}