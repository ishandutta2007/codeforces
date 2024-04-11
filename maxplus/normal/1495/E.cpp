#include <iostream>
#include <utility>

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

constexpr int N = 5e6, mod = 1e9 + 7;

int a[N], t[N], ans[N], n;

struct InputGenerator {
  int seed, base;

  int rnd() {
    return exchange(seed, (seed * (int64_t)base + 233) % mod);
  }

  InputGenerator() {
    n = $;
    int m = $;
    int pp = 0;
    while (m--) {
      int p = $, k = $;
      seed = $;
      base = $;
      for (int i = pp; i < p; ++i) {
        t[i] = rnd() % 2;
        a[i] = rnd() % k + 1;
      }
      pp = p;
    }
  }
};

int main() {
  InputGenerator{};
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int64_t s[2]{};
  for (int i = 0; i < n; ++i) {
    s[t[i]] += a[i];
  }
  bool winner = s[1] > s[0];
  if (winner == t[0] && s[1] != s[0]) {
    --a[0];
    ++ans[0];
  }
  int64_t carry = 0;
  for (auto pass: {0, 1})
  for (int i = 0; i < n; ++i) {
    int ch = t[i] == winner? min((int64_t)a[i], carry): a[i];
    a[i] -= ch;
    ans[i] += ch;
    carry += t[i] == winner? -ch: ch;
  }
  int64_t tans = 1;
  for (int i = 0; i < n; ++i) {
    (tans *= ((ans[i] ^ ((i + 1ll) * (i + 1))) + 1) % mod) %= mod;
  }
  print(tans);
}