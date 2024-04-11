#line 1 "library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR_(n) for (ll _ = 0; (_) < (ll)(n); ++(_))
#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))
#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))
#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

template <typename T>
T SUM(vector<T> &A) {
  T sum = T(0);
  for (auto &&a: A) sum += a;
  return sum;
}
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }

template <typename T, typename U>
T ceil(T x, U y) {
  return (x > 0 ? (x + y - 1) / y : x / y);
}

template <typename T, typename U>
T floor(T x, U y) {
  return (x > 0 ? x / y : (x - y + 1) / y);
}

template <typename T, typename U>
pair<T, T> divmod(T x, U y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

vi s_to_vi(const string& S, char first_char) {
  vi A(S.size());
  FOR(i, S.size()) { A[i] = S[i] - first_char; }
  return A;
}

template <typename T>
vector<T> cumsum(vector<T> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

template <typename CNT, typename T>
vc<CNT> bincount(const vc<T> &A, int size) {
  vc<CNT> C(size);
  for (auto &&x: A) { ++C[x]; }
  return C;
}

template <typename T>
vector<int> argsort(const vector<T> &A) {
  // stable
  vector<int> ids(A.size());
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
}

// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
  int n = len(A);
  assert(len(I) == n);
  vc<T> B(n);
  FOR(i, n) B[i] = A[I[i]];
  return B;
}
#line 1 "library/other/io.hpp"
// based on yosupo's fastio
#include <unistd.h>

namespace detail {
template <typename T, decltype(&T::is_modint) = &T::is_modint>
std::true_type check_value(int);
template <typename T>
std::false_type check_value(long);
} // namespace detail

template <typename T>
struct is_modint : decltype(detail::check_value<T>(0)) {};
template <typename T>
using is_modint_t = enable_if_t<is_modint<T>::value>;
template <typename T>
using is_not_modint_t = enable_if_t<!is_modint<T>::value>;

struct Scanner {
  FILE *fp;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf); }
    if (neg) ref = -ref;
    return true;
  }
  template <class T, is_modint_t<T> * = nullptr>
  bool read_single(T &ref) {
    long long val = 0;
    bool f = read_single(val);
    ref = T(val);
    return f;
  }
  bool read_single(double &ref) {
    string s;
    if (!read_single(s)) return false;
    ref = std::stod(s);
    return true;
  }
  bool read_single(char &ref) {
    string s;
    if (!read_single(s) || s.size() != 1) return false;
    ref = s[0];
    return true;
  }
  template <class T>
  bool read_single(vector<T> &ref) {
    for (auto &d: ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  template <class T, class U>
  bool read_single(pair<T, U> &p) {
    return (read_single(p.first) && read_single(p.second));
  }
  template <class A, class B, class C>
  bool read_single(tuple<A, B, C> &p) {
    return (read_single(get<0>(p)) && read_single(get<1>(p))
            && read_single(get<2>(p)));
  }
  template <class A, class B, class C, class D>
  bool read_single(tuple<A, B, C, D> &p) {
    return (read_single(get<0>(p)) && read_single(get<1>(p))
            && read_single(get<2>(p)) && read_single(get<3>(p)));
  }
  void read() {}
  template <class H, class... T>
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE *fp) : fp(fp) {}
};

struct Printer {
  Printer(FILE *_fp) : fp(_fp) {}
  ~Printer() { flush(); }

  static constexpr size_t SIZE = 1 << 15;
  FILE *fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write(const char &val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write('0');
      return;
    }
    if (val < 0) {
      write('-');
      val = -val; // todo min
    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 - i]; }
    pos += len;
  }
  void write(const string &s) {
    for (char c: s) write(c);
  }
  void write(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write(s[i]);
  }
  void write(const double &x) {
    ostringstream oss;
    oss << setprecision(15) << x;
    string s = oss.str();
    write(s);
  }
  void write(const long double &x) {
    ostringstream oss;
    oss << setprecision(15) << x;
    string s = oss.str();
    write(s);
  }
  template <class T, is_modint_t<T> * = nullptr>
  void write(T &ref) {
    write(ref.val);
  }
  template <class T>
  void write(const vector<T> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  template <class T, class U>
  void write(const pair<T, U> &val) {
    write(val.first);
    write(' ');
    write(val.second);
  }
  template <class A, class B, class C>
  void write(const tuple<A, B, C> &val) {
    auto &[a, b, c] = val;
    write(a);
    write(' ');
    write(b);
    write(' ');
    write(c);
  }
  template <class A, class B, class C, class D>
  void write(const tuple<A, B, C, D> &val) {
    auto &[a, b, c, d] = val;
    write(a);
    write(' ');
    write(b);
    write(' ');
    write(c);
    write(' ');
    write(d);
  }
  template <class T, size_t S>
  void write(const array<T, S> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  void write(i128 val) {
    string s;
    bool negative = 0;
    if(val < 0){
      negative = 1;
      val = -val;
    }
    while (val) {
      s += '0' + int(val % 10);
      val /= 10;
    }
    if(negative) s += "-";
    reverse(all(s));
    if (len(s) == 0) s = "0";
    write(s);
  }
};

Scanner scanner = Scanner(stdin);
Printer printer = Printer(stdout);

void flush() { printer.flush(); }
void print() { printer.write('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  printer.write(head);
  if (sizeof...(Tail)) printer.write(' ');
  print(forward<Tail>(tail)...);
}

void read() {}
template <class Head, class... Tail>
void read(Head &head, Tail &... tail) {
  scanner.read(head);
  read(tail...);
}

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHAR(...)      \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
#line 2 "library/string/suffixarray.hpp"
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

  void induced_sort(const std::vector<int>& vect, int val_range,
                    std::vector<int>& SA, const std::vector<bool>& sl,
                    const std::vector<int>& lms_idx) {
    std::vector<int> l(val_range, 0), r(val_range, 0);
    for (int c: vect) {
      if (c + 1 < val_range) ++l[c + 1];
      ++r[c];
    }
    std::partial_sum(l.begin(), l.end(), l.begin());
    std::partial_sum(r.begin(), r.end(), r.begin());
    std::fill(SA.begin(), SA.end(), -1);
    for (int i = (int)lms_idx.size() - 1; i >= 0; --i)
      SA[--r[vect[lms_idx[i]]]] = lms_idx[i];
    for (int i: SA)
      if (i >= 1 && sl[i - 1]) SA[l[vect[i - 1]]++] = i - 1;
    std::fill(r.begin(), r.end(), 0);
    for (int c: vect) ++r[c];
    std::partial_sum(r.begin(), r.end(), r.begin());
    for (int k = (int)SA.size() - 1, i = SA[k]; k >= 1; --k, i = SA[k])
      if (i >= 1 && !sl[i - 1]) { SA[--r[vect[i - 1]]] = i - 1; }
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

  std::vector<int> calc_suffix_array(const std::string& s,
                                     const char first = 'a',
                                     const char last = 'z') {
    std::vector<int> vect(s.size() + 1);
    std::copy(std::begin(s), std::end(s), std::begin(vect));
    for (auto& x: vect) x -= (int)first - 1;
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
    for (auto& x: vect)
      x = lower_bound(ss.begin(), ss.end(), x) - ss.begin() + 1;
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
#line 2 "library/string/sort_all_substring.hpp"

/*
dp[l][r] := S[l:r] 
O(N^2)
*/
template <typename STRING>
vc<vc<int>> sort_all_substring(STRING S) {
  int n = len(S);
  SuffixArray sa(S);
  auto& SA = sa.SA;
  auto& LCP = sa.LCP;
  int nxt = 0;
  vv(int, DP, n, n + 1, -1);
  FOR(i, len(SA)) {
    auto L = SA[i];
    FOR3(k, 1, n - L + 1) {
      int R = L + k;
      if (i > 0 && LCP[i - 1] >= k)
        DP[L][R] = DP[SA[i - 1]][SA[i - 1] + k];
      else
        DP[L][R] = nxt++;
    }
  }
  return DP;
}
#line 4 "main.cpp"

void solve() {
  LL(N, M, K);
  STR(S);
  auto rank = sort_all_substring(S);

  auto check = [&](ll rk) -> bool {
    /*
    rank >= rk  substring 
    M K 
    */
    // left ->  r  min
    vi TO(N, N + 1);
    FOR(l, N) { FOR3(r, l + 1, N + 1) if (rank[l][r] >= rk) chmin(TO[l], r); }

    vi DP(N + 1);
    DP[0] = 1;
    FOR_(M) {
      vc<i128> newDP(N + 1);
      FOR(l, N) {
        int to = TO[l];
        if (to > N) continue;
        newDP[to] += DP[l];
      }
      newDP = cumsum(newDP, 0);
      FOR(i, N + 1) DP[i] = min<i128>(newDP[i], K);
    }
    return DP[N] >= K;
  };

  ll mx = 0;
  FOR(i, N) chmax(mx, MAX(rank[i]));

  ll rk = binary_search(check, 0, mx + 1);
  FOR(l, N) FOR(r, N + 1) {
    if (rank[l][r] == rk) { return print(S.substr(l, r - l)); }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}