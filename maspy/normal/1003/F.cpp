#line 1 "main.cpp"
#include <bits/stdc++.h>
#line 3 "/home/maspy/library/my_template.hpp"

using namespace std;

using ll = long long;
using ld = long double;
#define int ll
using pi = pair<int, int>;
using vi = vector<int>;

#define FOR(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define FOR3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define FOR_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define all(x) x.begin(), x.end()

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

// [
ll read() {
  ll i;
  cin >> i;
  return i;
}

pi read2(int off = 0) {
  ll a, b;
  cin >> a >> b;
  return {a + off, b + off};
}

tuple<ll, ll, ll> read3() {
  ll a, b, c;
  cin >> a >> b >> c;
  return {a, b, c};
}

vi read_vec(int n, int off = 0) {
  vi A(n);
  for (auto&& x : A) {
    cin >> x;
    x += off;
  }
  return A;
}

string read_str() {
  string s;
  cin >> s;
  return s;
}
// ]

// [
template <typename T>
void print(T x) {
  cout << x << "\n";
}

template <typename A, typename B>
void print(A x, B y, string sep = " ") {
  cout << x << sep << y << "\n";
}

template <typename A, typename B, typename C>
void print(A x, B y, C z, string sep = " ") {
  cout << x << sep << y << sep << z << "\n";
}

template <typename T>
void print_seq(T begin, T end, string sep = " ") {
  if (begin != end) {
    cout << *(begin++);
    for (auto it = begin; it != end; it++) {
      cout << sep << (*it);
    }
  }
  cout << "\n";
}
template <typename T>
void print_all(T A, string sep = " ") {
  print_seq(all(A), sep);
}
// ]

template <typename T>ll sum(T A){return accumulate(all(A), 0);}

template <typename T>vector<T> cumsum(vector<T> A) {
  ll N = A.size(); vector<T> B(N + 1); B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vi bin_count(vi& A, ll size){
  vi C(size);
  for(auto&& x : A){ ++C[x]; }
  return C;
}

template <typename T>
struct vec2d {
  ll H, W;
  vector<vector<T>> data;
  vec2d(ll H, ll W) : H(W), W(W), data(H, vector<T>(W)) {}
  void fill(T x) {
    FOR(i, H) { FOR(j, W) data[i][j] = x; }
  }
  void print() { FOR(i, H) print_all(data[i]); }
  vector<T>& operator[](ll i) { return data[i]; }
};

template<class T, class U>bool chmax(T &a, const U &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T, class U>bool chmin(T &a, const U &b) { if (b<a) { a=b; return 1; } return 0; }
#line 2 "/home/maspy/library/string/rollinghash.hpp"

struct RollingHash {
  static const uint64_t mod = (1ull << 61ull) - 1;
  using uint128_t = __uint128_t;
  vector<uint64_t> power;
  const uint64_t base;

  static inline uint64_t add(uint64_t a, uint64_t b) {
    if ((a += b) >= mod) a -= mod;
    return a;
  }

  static inline uint64_t mul(uint64_t a, uint64_t b) {
    uint128_t c = (uint128_t)a * b;
    return add(c >> 61, c & mod);
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
#line 4 "main.cpp"

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  auto RH = RollingHash();
  int N = read();
  string S;
  getline(cin, S);  // 1 
  getline(cin, S);
  S += " ";

  auto H = RH.build(S);

  vi idx(N + 1);
  ll now = 0;
  FOR(i, S.size()) {
    if (S[i] == ' ') {
      idx[++now] = i + 1;
    }
  }

  auto calc = [&](ll l, ll r) { return RH.query(H, idx[l], idx[r]); };

  ll best = 0;

  FOR(i, N) {
    FOR3(j, i + 1, N) {
      // [i, j) 
      auto hash = calc(i, j);
      auto sz = idx[j] - idx[i];
      ll cnt = 1;
      ll l = j;
      auto get_nxt = [&](ll k) -> ll {
        chmax(l, k);
        while (l < N && idx[l] - idx[k] < sz) {
          ++l;
        }
        if (idx[l] - idx[k] == sz && calc(k, l) == hash) return l;
        return -1;
      };
      ll k = j;
      while (k < N) {
        auto to = get_nxt(k);
        if (to == -1) {
          ++k;
          continue;
        }
        ++cnt;
        k = to;
      }
      if (cnt == 1) continue;
      ll diff = sz - (j - i + 1);
      chmax(best, cnt * diff);
    }
  }
  auto ans = S.size() - 1 - best;
  print(ans);
  return 0;
}