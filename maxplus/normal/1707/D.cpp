//#pragma GCC optimize "tree-vectorize"
//#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <complex>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() const { T t; cin >> t; return t; } operator X() const { return operator()(); } template <typename T> operator T() const { return operator()<T>(); } template <auto=0> string operator~() const { return *this; } char operator!() const { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
auto operator>>(istream& in, auto&& p) -> decltype(p.first, p.second, in) { return in >> p.first >> p.second; }
auto operator<<(ostream& out, const auto& p) -> decltype(p.first, p.second, out) { return out << p.first << ' ' << p.second; }
template <typename It> struct range { It first, last; constexpr range() {} constexpr range(It first, It last) : first{first}, last{last} {} constexpr range(It first, auto n) : range{first, first + n} {} constexpr range(auto&& c) : range{c.begin(), c.end()} {} constexpr It begin() const { return first; } constexpr It end() const { return last; } constexpr int size() const { return last - first; } constexpr const auto& operator[](int i) const { return first[i]; } constexpr auto& operator[](int i) { return first[i]; } range<reverse_iterator<It>> rev() const { return {reverse_iterator(last), reverse_iterator(first)}; } }; range(auto&& c) -> range<decltype(c.begin())>;
template <int from, int which> auto getfield(const auto& a) -> const auto& { static_assert(1 <= which && which <= from && from <= 5); auto fix = [](auto& x) -> auto& { return x; }; if constexpr (from == 1) { if constexpr (is_scalar_v<decay_t<decltype(a)>>) { if constexpr (which == 1) return fix(a); } else { auto& [a1] = a; if constexpr (which == 1) return fix(a1); } } else if constexpr (from == 2) { auto& [a1, a2] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); } else if constexpr (from == 3) { auto& [a1, a2, a3] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); } else if constexpr (from == 4) { auto& [a1, a2, a3, a4] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); } else if constexpr (from == 5) { auto& [a1, a2, a3, a4, a5] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); if constexpr (which == 5) return fix(a5); } }
template <int from, int which> struct GetField { decltype(auto) operator()(const auto& a) { return getfield<from, which>(a); } };
template <int from, int which, typename Cmp = equal_to<>> struct CompareField { bool operator()(const auto& a, const auto& b) const { return Cmp{}(getfield<from, which>(a), getfield<from, which>(b)); } };
template <int from, int which, int... whichs> struct Ordering { bool operator()(const auto& a, const auto& b) const { auto& aa = getfield<from, labs(which)>(a), & bb = getfield<from, labs(which)>(b); if (aa < bb) { return which > 0; } else if (bb < aa) { return which < 0; } else if constexpr (sizeof...(whichs)) { return Ordering<from, whichs...>{}(a, b); } return 0; } };
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (0 < a) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }
void lshift(auto& first, auto& second, auto&... args) { first = second; if constexpr (sizeof...(args)) lshift(second, args...); } void rshift(auto& first, auto& second, auto&... args) { if constexpr (sizeof...(args)) rshift(second, args...); second = first; }
void lrotate(auto& arg, auto&... args) { auto t = arg; lshift(arg, args...); ([](auto&t)->auto&{return t;}(args), ...) = t; } void rrotate(auto& arg, auto&... args) { auto t = ([](auto&t)->auto&{return t;}(args), ...); rshift(arg, args...); arg = t; }
template <typename T, typename Cmp = greater<>> using PQ = priority_queue<T, vector<T>, Cmp>;

constexpr int N = 2000;

template <typename T>
struct GenerateOperators {
  template <typename LowPriority = void>
  constexpr friend T operator+(T lhs, const auto& rhs) { return lhs += rhs; }
  template <typename LowPriority = void>
  constexpr friend T& operator-=(T& lhs, const T& rhs) { return lhs += -rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator-(T lhs, const auto& rhs) { return lhs -= rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator*(T lhs, const auto& rhs) { return lhs *= rhs; }
  template <typename LowPriority = void>
  constexpr friend T& operator/=(T& lhs, const T& rhs) { return lhs *= ~rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator/(T lhs, const auto& rhs) { return lhs /= rhs; }
  template <typename LowPriority = void>
  constexpr friend bool operator==(const T& lhs, const auto& rhs) { return !(lhs < rhs || lhs > rhs); }
  template <typename LowPriority = void>
  constexpr friend bool operator!=(const T& lhs, const auto& rhs) { return !(lhs == rhs); }
  template <typename LowPriority = void>
  constexpr friend bool operator>(const T& lhs, const auto& rhs) { return rhs < lhs; }
  template <typename LowPriority = void>
  constexpr friend bool operator<=(const T& lhs, const auto& rhs) { return !(lhs > rhs); }
  template <typename LowPriority = void>
  constexpr friend bool operator>=(const T& lhs, const auto& rhs) { return !(lhs < rhs); }
};

template <typename T>
constexpr T fpow(T a, uint32_t p) {
  T res = 1;
  while (p) {
    if (p & 1) {
      res *= a;
    }
    a *= a;
    p >>= 1;
  }
  return res;
}

struct BarrettMod {
  uint32_t mod;
  uint64_t inv;

  void init(uint32_t m) { mod = m; inv = -1ull / m + 1; }

  friend uint64_t operator%(uint64_t a, const BarrettMod& mod) {
    #ifdef __SIZEOF_INT128__
      uint32_t v = a - uint64_t(__uint128_t(a) * mod.inv >> 64) * mod.mod;
      return v += v >= mod.mod? mod.mod: 0;
    #else
      return a % mod.mod;
    #endif
  }

  operator uint32_t() { return mod; }
} mod;

struct ModNum: GenerateOperators<ModNum> {
  uint32_t val;

  constexpr ModNum(uint32_t val = 0) : val{val} {}

  ModNum& operator+=(const ModNum& other) {
    val += other.val;
    if (val >= mod) {
      val -= mod;
    }
    return *this;
  }

  template <bool constexpr_friendly = true>
  ModNum& operator*=(const ModNum& other) {
    if (constexpr_friendly || INTPTR_MAX == INT64_MAX) {
      val = (uint64_t)val * other.val % mod;
//    } else if consteval {
//      val = (uint64_t)val * other.val % mod;
    } else {
      asmmul(other);
    }
    return *this;
  }

  void asmmul(const ModNum& other) {
    uint32_t junk;
    asm("mul %0\n\tdivl %3\n\t" : "+d" (val), "=a" (junk) : "a" (other.val), "rm" (mod) : "cc");
  }

  ModNum& operator-=(const ModNum& rhs) { return *this += mod - rhs.val; }
  ModNum operator-() const { return val > 0? mod - val: -val; }
  ModNum operator!() const { return val > 1? mod + 1 - val: 1 - val; }
  ModNum operator~() const { return fpow(*this, mod - 2); }
  friend ostream& operator<<(ostream& out, const ModNum& a) { return out << a.val; }
  explicit operator uint32_t() const { return val; }
};constexpr ModNum operator "" m (unsigned long long v) { return v; }

struct Factorial {
  constexpr static int N = ::N;

  void init() {
    ModNum cur = fact[0] = 1;
    for (int i = 1; i < N; ++i) {
      fact[i] = cur *= i;
    }
    cur = nfact[N - 1] = ~fact[N - 1];
    for (int i = N; --i; ) {
      nfact[i - 1] = cur *= i;
    }
  }

  ModNum operator[](int n) { return fact[n]; }
  ModNum operator()(int n) { return nfact[n]; }
  ModNum inv(int n) { return nfact[n] * fact[n - 1]; }
  ModNum a(int n, int k) { return fact[n] * nfact[n - k]; }
  ModNum inva(int n, int k) { return nfact[n] * fact[n - k]; }
  ModNum operator()(int n, int k) { return a(n, k) * nfact[k]; }
  ModNum invc(int n, int k) { return inva(n, k) * fact[k]; }
  ModNum cat(int n, int k = -1) { return k > n? 0: k == -1 || k == n? a(n + n, n) * nfact[n + 1]: a(n + k, n) * nfact[n + 1] * (n - k + 1); }
  ModNum s(int n) { return (*this)(n, n / 2); }

private:
  ModNum fact[N], nfact[N];
} fact;

int n;
vector<int> nei[N];

vector<ModNum> solve(int v, int p) {
  vector<vector<ModNum>> ch;
  for (auto u: nei[v]) if (u != p) {
    ch.push_back(solve(u, v));
  }
  vector<ModNum> ans(n - 1, 1);
  vector<vector<ModNum>> chpspl(ch.size()), chpspr(ch.size()), chps(ch.size());
  for (int i = 0; i < ch.size(); ++i) {
    chps[i].resize(n - 1);
    partial_sum(ch[i].begin(), ch[i].end(), chps[i].begin());
  }
  if (ch.size()) {
    chpspl[0] = chpspr.back() = ans;
    auto vmul = [](const auto& a, auto b) { transform(a.begin(), a.end(), b.begin(), b.begin(), multiplies<>{}); return b; };
    partial_sum(chps.begin(), chps.end() - 1, chpspl.begin() + 1, vmul);
    partial_sum(chps.rbegin(), chps.rend() - 1, chpspr.rbegin() + 1, vmul);
    ans = vmul(chpspl.back(), chps.back());
  }
  if (v != p)
  for (int i = 0; i < ch.size(); ++i) if (ModNum ps = 0; 1)
  for (int b = 1; b < n - 1; ++b) {
    ps += chpspl[i][b - 1] * chpspr[i][b - 1];
    ans[b] += ps * ch[i][b];
  }
  return ans;
}

namespace kactl {

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}

typedef vector<ll> vl;
vl convMod(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	vl res(sz(a) + sz(b) - 1);
	int B=32-__builtin_clz(sz(res)), n=1<<B, cut=int(sqrt(mod.mod));
	vector<C> L(n), R(n), outs(n), outl(n);
	rep(i,0,sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
	rep(i,0,sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
	fft(L), fft(R);
	rep(i,0,n) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}
	fft(outl), fft(outs);
	rep(i,0,sz(res)) {
		ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
		ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
		res[i] = ((av % mod.mod * cut + bv) % mod.mod * cut + cv) % mod.mod;
	}
	return res;
}

}  // namespace kactl

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  n = $;
  mod.init($);
  fact.init();
  for (int i = 1; i < n; ++i) {
    int u = $ - 1, v = $ - 1;
    nei[u].push_back(v);
    nei[v].push_back(u);
  }
  auto v = solve(0, 0);
  kactl::vl u(n - 1), t(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    t[i] = fact(i).val;
    if (i & 1) t[i] = mod - t[i];
    u[i] = (v[i] * fact(i + 1)).val;
  }
  u = kactl::convMod(u, t);
  for (int i = 0; i < n - 1; ++i) {
    v[i] = u[i] * fact[i + 1];
  }
  print(v);
}