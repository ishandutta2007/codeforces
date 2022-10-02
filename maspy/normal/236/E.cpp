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
int bsf(uint x) {
  return __builtin_ctz(x);
}
int bsf(ull x) {
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
    assert(R <= N_);
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
  
  template<class F>
  int max_right(int L, F &check){
    assert(0<=L && L <= N_ && check(T_unit));
    if(L==N_) return N_;
    L += N;
    T sm = T_unit;
    do {
      while(L%2==0) L>>=1;
      if(!check(seg_f(sm, dat[L]))){
        while(L < N) {
          L = 2 * L;
          if(check(seg_f(sm, dat[L]))){
            sm = seg_f(sm, dat[L]);
            L++;
          }
        }
        return L - N;
      }
      sm = seg_f(sm, dat[L]);
      L++;
    } while((L&-L)!=L);
    return N_;
  }

  template<class F>
  int min_left(int R, F &check){
    assert(0<=R && R <= N_ && check(T_unit));
    if(R==0) return 0;
    R += N;
    T sm = T_unit;
    do {
      --R;
      while(R>1 && (R%2)) R>>=1;
      if(!check(seg_f(dat[R], sm))){
        while(R < N) {
          R = 2 * R + 1;
          if(check(seg_f(dat[R], sm))){
            sm = seg_f(dat[R], sm);
            R--;
          }
        }
        return R + 1 - N;
      }
      sm = seg_f(dat[R], sm);
    } while((R&-R)!=R);
    return 0;
  }
};
#line 2 "/home/maspy/library/string/rollinghash.hpp"

struct RollingHash {
  static const uint64_t mod = (1ull << 61ull) - 1;
  vector<uint64_t> power;
  const uint64_t base;

  static inline uint64_t add(uint64_t a, uint64_t b) {
    if ((a += b) >= mod) a -= mod;
    return a;
  }

  static inline uint64_t mul(uint64_t a, uint64_t b) {
    const uint64_t MASK30 = (1LL<<30) - 1;
    const uint64_t MASK31 = (1LL<<31) - 1;
    const uint64_t MASK61 = (1LL<<61) - 1;
    uint64_t au = a >> 31, ad = a & MASK31;
    uint64_t bu = b >> 31, bd = b & MASK31;
    uint64_t x = ad * bu + au * bd;
    uint64_t xu = x >> 30, xd = x & MASK30;
    x = au * bu * 2 + xu + (xd << 31) + ad * bd;
    xu = x >> 61, xd = x & MASK61;
    x = xu + xd;
    if(x >= MASK61) x -= MASK61;
    return x;
  }

  static inline uint64_t generate_base() {
    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> rand(1, RollingHash::mod - 1);
    return rand(mt);
  }

  inline void expand(size_t sz) {
    if (power.size() < sz + 1) {
      int pre_sz = (int)power.size();
      power.resize(sz + 1);
      for (int i = pre_sz - 1; i < sz; i++) {
        power[i + 1] = mul(power[i], base);
      }
    }
  }

  explicit RollingHash(uint64_t base = generate_base()) : base(base), power{1} {}

  vector<uint64_t> build(const string& s) const {
    int sz = s.size();
    vector<uint64_t> hashed(sz + 1);
    for (int i = 0; i < sz; i++) {
      hashed[i + 1] = add(mul(hashed[i], base), s[i]);
    }
    return hashed;
  }

  template <typename T>
  vector<uint64_t> build(const vector<T>& s) const {
    int sz = s.size();
    vector<uint64_t> hashed(sz + 1);
    for (int i = 0; i < sz; i++) {
      hashed[i + 1] = add(mul(hashed[i], base), s[i]);
    }
    return hashed;
  }

  uint64_t query(const vector<uint64_t>& s, int l, int r) {
    expand(r - l);
    return add(s[r], mod - mul(s[l], power[r - l]));
  }

  uint64_t combine(uint64_t h1, uint64_t h2, size_t h2len) {
    expand(h2len);
    return add(mul(h1, power[h2len]), h2);
  }

  int lcp(const vector<uint64_t>& a, int l1, int r1, const vector<uint64_t>& b, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = 0, high = len + 1;
    while (high - low > 1) {
      int mid = (low + high) / 2;
      if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))
        low = mid;
      else
        high = mid;
    }
    return low;
  }
};
#line 2 "/home/maspy/library/string/suffixarray.hpp"
using namespace std;

#define int long long
struct SuffixArray {
  vector<int> SA;
  vector<int> ISA;
  vector<int> LCP;

  SuffixArray(string& s, const char first = 'a', const char last = 'z') {
    SA = calc_suffix_array(s, first, last);
    calc_LCP(s);
  }

  SuffixArray(vector<int>& s) {
    SA = calc_suffix_array(s);
    calc_LCP(s);
  }

  void induced_sort(const std::vector<int>& vect, int val_range, std::vector<int>& SA, const std::vector<bool>& sl,
                    const std::vector<int>& lms_idx) {
    std::vector<int> l(val_range, 0), r(val_range, 0);
    for (int c : vect) {
      if (c + 1 < val_range) ++l[c + 1];
      ++r[c];
    }
    std::partial_sum(l.begin(), l.end(), l.begin());
    std::partial_sum(r.begin(), r.end(), r.begin());
    std::fill(SA.begin(), SA.end(), -1);
    for (int i = (int)lms_idx.size() - 1; i >= 0; --i) SA[--r[vect[lms_idx[i]]]] = lms_idx[i];
    for (int i : SA)
      if (i >= 1 && sl[i - 1]) SA[l[vect[i - 1]]++] = i - 1;
    std::fill(r.begin(), r.end(), 0);
    for (int c : vect) ++r[c];
    std::partial_sum(r.begin(), r.end(), r.begin());
    for (int k = (int)SA.size() - 1, i = SA[k]; k >= 1; --k, i = SA[k])
      if (i >= 1 && !sl[i - 1]) {
        SA[--r[vect[i - 1]]] = i - 1;
      }
  }

  std::vector<int> SA_IS(const std::vector<int>& vect, int val_range) {
    const int n = vect.size();
    std::vector<int> SA(n), lms_idx;
    std::vector<bool> sl(n);
    sl[n - 1] = false;
    for (int i = n - 2; i >= 0; --i) {
      sl[i] = (vect[i] > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i + 1]));
      if (sl[i] && !sl[i + 1]) lms_idx.push_back(i + 1);
    }
    std::reverse(lms_idx.begin(), lms_idx.end());
    induced_sort(vect, val_range, SA, sl, lms_idx);
    std::vector<int> new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());
    for (int i = 0, k = 0; i < n; ++i)
      if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) {
        new_lms_idx[k++] = SA[i];
      }
    int cur = 0;
    SA[n - 1] = cur;
    for (size_t k = 1; k < new_lms_idx.size(); ++k) {
      int i = new_lms_idx[k - 1], j = new_lms_idx[k];
      if (vect[i] != vect[j]) {
        SA[j] = ++cur;
        continue;
      }
      bool flag = false;
      for (int a = i + 1, b = j + 1;; ++a, ++b) {
        if (vect[a] != vect[b]) {
          flag = true;
          break;
        }
        if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {
          flag = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));
          break;
        }
      }
      SA[j] = (flag ? ++cur : cur);
    }
    for (size_t i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];
    if (cur + 1 < (int)lms_idx.size()) {
      auto lms_SA = SA_IS(lms_vec, cur + 1);
      for (size_t i = 0; i < lms_idx.size(); ++i) {
        new_lms_idx[i] = lms_idx[lms_SA[i]];
      }
    }
    induced_sort(vect, val_range, SA, sl, new_lms_idx);
    return SA;
  }

  std::vector<int> calc_suffix_array(const std::string& s, const char first = 'a', const char last = 'z') {
    std::vector<int> vect(s.size() + 1);
    std::copy(std::begin(s), std::end(s), std::begin(vect));
    for (auto& x : vect) x -= (int)first - 1;
    vect.back() = 0;
    auto ret = SA_IS(vect, (int)last - (int)first + 2);
    ret.erase(ret.begin());
    return ret;
  }

  std::vector<int> calc_suffix_array(const vector<int>& s) {
    vector<int> ss = s;
    sort(ss.begin(), ss.end());
    ss.erase(unique(ss.begin(), ss.end()), ss.end());

    std::vector<int> vect(s.size() + 1);
    std::copy(std::begin(s), std::end(s), std::begin(vect));
    for (auto& x : vect) x = lower_bound(ss.begin(), ss.end(), x) - ss.begin() + 1;
    vect.back() = 0;
    auto ret = SA_IS(vect, *max_element(vect.begin(), vect.end()) + 2);
    ret.erase(ret.begin());
    return ret;
  }

  void calc_LCP(const std::string& s) {
    int n = s.size(), k = 0;
    ISA.resize(n);
    LCP.resize(n);
    for (int i = 0; i < n; i++) ISA[SA[i]] = i;
    for (int i = 0; i < n; i++, k ? k-- : 0) {
      if (ISA[i] == n - 1) {
        k = 0;
        continue;
      }
      int j = SA[ISA[i] + 1];
      while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
      LCP[ISA[i]] = k;
    }
    LCP.resize(n - 1);
  }

  void calc_LCP(const vector<int>& s) {
    int n = s.size(), k = 0;
    ISA.resize(n);
    LCP.resize(n);
    for (int i = 0; i < n; i++) ISA[SA[i]] = i;
    for (int i = 0; i < n; i++, k ? k-- : 0) {
      if (ISA[i] == n - 1) {
        k = 0;
        continue;
      }
      int j = SA[ISA[i] + 1];
      while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
      LCP[ISA[i]] = k;
    }
    LCP.resize(n - 1);
  }
};
#line 6 "main.cpp"

void solve() {
  STR(S);
  S += '~';
  LL(N);
  vi IDX = {S.size()};
  FOR(_, N) {
    STR(T);
    S += T + T + '~';
    IDX.eb(S.size());
  }

  SuffixArray sa(S, 'a', '~');
  auto& SA = sa.SA;
  auto& ISA = sa.ISA;
  auto& LCP = sa.LCP;

  vi FRM_S(S.size());
  FOR(i, S.size()) if (SA[i] < IDX[0]) FRM_S[i] = 1;
  vi FRM_Sc = cumsum(FRM_S);

  RollingHash RH;
  auto SH = RH.build(S);

  const ll INF = 1LL << 60;
  SegTree<ll> seg([](ll x, ll y) { return min(x, y); }, INF);
  seg.init(LCP.size());
  seg.build(LCP);

  FOR(i, N) {
    set<ll> DONE;
    ll ANS = 0;
    ll n = (IDX[i + 1] - IDX[i] - 1) / 2;
    FOR3(s, IDX[i], IDX[i] + n) {
      ll hs = RH.query(SH, s, s + n);
      if (DONE.count(hs)) continue;
      DONE.insert(hs);
      ll p = ISA[s];
      auto check = [&](ll x) -> bool { return x >= n; };
      ll l = seg.min_left(p, check);
      ll r = seg.max_right(p, check) + 1;
      ll cnt = FRM_Sc[r] - FRM_Sc[l];
      ANS += cnt;
      // print(S.substr(s, n), RH.query(SH, s, s + n), cnt);
    }
    print(ANS);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}