#include <bits/stdc++.h>

using namespace std;

template <typename T> T mod_inv_in_range(T a, T m) {
  // assert(0 <= a && a < m);
  T x = a, y = m;
  T vx = 1, vy = 0;
  while (x) {
    T k = y / x;
    y %= x;
    vy -= k * vx;
    std::swap(x, y);
    std::swap(vx, vy);
  }
  assert(y == 1);
  return vy < 0 ? m + vy : vy;
}
 
template <typename T> T mod_inv(T a, T m) {
  a %= m;
  a = a < 0 ? a + m : a;
  return mod_inv_in_range(a, m);
}
 
template <int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");
 
private:
  using ll = long long;
 
  int v;
 
public:
 
  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
  friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
 
  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
 
  modnum inv() const {
    modnum res;
    res.v = mod_inv_in_range(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD-v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }
 
  modnum operator- () const {
    return neg();
  }
  modnum operator+ () const {
    return modnum(*this);
  }
 
  modnum& operator ++ () {
    v ++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }
  modnum& operator += (const modnum& o) {
    v -= MOD-o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum& operator -= (const modnum& o) {
    v -= o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum& operator *= (const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator /= (const modnum& o) {
    return *this *= o.inv();
  }
 
  friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
  friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    using num = modnum<998244353>;

    const int V = 5050;
    vector<num> fact(V + 1);
    fact[0] = 1; for (int i = 1; i <= V; ++i) fact[i] = fact[i - 1] * i;
    vector<num> ifact(V + 1);
    ifact[V] = fact[V].inv();
    for (int i = V; i > 0; --i) ifact[i - 1] = ifact[i] * i;

    auto choose = [&](int N, int K) {
        if (N < K || K < 0) return num(0);
        return fact[N] * ifact[K] * ifact[N - K];
    };

    int T; cin >> T;
    while (T--) {

      int N; cin >> N;
      vector<int> cnt(N + 1);
     for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        ++cnt[a];
      }

      int M = N / 2;
      vector<num> dp(M + 1);
      dp[0] = 1;
      int tot = 0;
      for (int v = N; v > 0; --v) {
          int c = cnt[v];
          vector<num> ndp(M + 1);
          for (int i = 0; i <= M; ++i) {
              num ways = dp[i];
              if (c > 0) {
                  int choice = (i - 1) - (tot - i);
                  if (i == M) choice ++;
                  ways *= choose(choice, c);
              }
              ndp[i] += ways;
          }

          if (c > 0) {
               for (int i = 0; i < M; ++i) {
                  num ways = dp[i];
                  if (c > 1) ways *= choose((i - 1) - (tot - i), c - 1);
                  ndp[i + 1] += ways;
              }
          }
          dp = ndp;

      
          tot += c;
      }
      cout << dp[M] << '\n';
    }
    return 0;
}