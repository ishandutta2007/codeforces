#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
auto print(const auto& c) -> decltype(c.begin(), void()) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }


template <typename T>
struct ArithmeticOperators {
  template <typename LowPriority = void>
  constexpr friend T operator+(T lhs, const T& rhs) { return lhs += rhs; }
  template <typename LowPriority = void>
  constexpr friend T& operator-=(T& lhs, const T& rhs) { return lhs += -rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator-(T lhs, const T& rhs) { return lhs -= rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator*(T lhs, const T& rhs) { return lhs *= rhs; }
  template <typename LowPriority = void>
  constexpr friend T& operator/=(T& lhs, const T& rhs) { return lhs *= ~rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator/(T lhs, const T& rhs) { return lhs /= rhs; }
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

constexpr int mod = 998244353;

struct ModNum: ArithmeticOperators<ModNum> {
  uint32_t val;

  constexpr ModNum(uint32_t val = 0) : val{val} {}

  constexpr ModNum& operator+=(const ModNum& other) {
    val += other.val;
    if (val >= mod) {
      val -= mod;
    }
    return *this;
  }

  template <bool constexpr_friendly = true>
  constexpr ModNum& operator*=(const ModNum& other) {
    if constexpr (constexpr_friendly || INTPTR_MAX == INT64_MAX) {
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

  constexpr ModNum& operator-=(const ModNum& rhs) { return *this += mod - rhs.val; }
  constexpr ModNum operator-() const { return val > 0? mod - val: -val; }
  constexpr ModNum operator!() { return 1 - *this; }
  constexpr ModNum operator~() { return fpow(*this, mod - 2); }
  friend ostream& operator<<(ostream& out, const ModNum& a) { return out << a.val; }
  constexpr explicit operator uint32_t() const { return val; }
};constexpr ModNum operator "" m (unsigned long long v) { return v; }

constexpr int N = 400;

int d[N][N];
vector<int> nei_[N];
int allnei[1200];
int* nei[N + 1]{allnei};
queue<int> q;

ModNum ans[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, m = $;
  memset(d, 63, sizeof d);
  for (int i = 0; i < m; ++i) {
    int a = $ - 1, b = $ - 1;
    nei_[a].push_back(b);
    nei_[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) {
    sort(nei_[i].begin(), nei_[i].end());
    nei[i + 1] = copy(nei_[i].begin(), nei_[i].end(), nei[i]);
  }
  for (int i = 0; i < n; ++i) {
    d[i][i] = 0;
    q.push(i);
    while (q.size()) {
      int j = q.front(); q.pop();
      for (auto k: range{nei[j], nei[j + 1]}) if (d[i][k] == -1u / 255 * 63) {
        d[i][k] = d[i][j] + 1;
        q.push(k);
      }
    }
  }
  for (int i = 0; i < n; ++i)
  for (int j = 0; j <= i; ++j) {
    ans[i][j] = 1;
    int k = 0, cand = 0, inpath = d[i][0] + d[j][0] == d[i][j];
    for (const int* p = nei[0]; p != nei[n]; ++p) {
      cand += d[i][*p] == d[i][k] - 1 && d[j][*p] == d[j][k] + 2 * inpath - 1;
      if (p == nei[k + 1] - 1) {
        if (__builtin_expect(k != i, 1)) {
          if (__builtin_expect(inpath? cand != 1: !cand, 0)) {
            ans[i][j] = 0;
            break;
          }
          ans[i][j] *= cand;
        }
        ++k;
        cand = 0;
        inpath = d[i][k] + d[j][k] == d[i][j];
      }
    }
    ans[j][i] = ans[i][j];
  }
  for (const auto& row: range{ans, n}) {
    cout << range{row, n} << '\n';
  }
}