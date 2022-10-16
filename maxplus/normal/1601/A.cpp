#include <iostream>
#include <numeric>

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
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 2e5, L = 30;

int a[N];

uint64_t fgcd(uint64_t a, uint64_t b) {
  int c = __builtin_ctzll(a | b);
  a >>= __builtin_ctzll(a);
  b >>= __builtin_ctzll(b);
  if (a < b) {
    swap(a, b);
  }
  while (b) {
    do {
      a -= b;
      a >>= __builtin_ctzll(a);
    } while (a >= b);
    swap(a, b);
  }
  return a << c;
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $, ans = 0;
    cin >> range{a, n};
    int cnt[L]{};
    for (auto i: range{a, n}) {
      while (i) {
        ++cnt[__builtin_ctz(i)];
        i &= i - 1;
      }
    }
    ans = accumulate(cnt, cnt + L, 0, fgcd);
    for (int k = 1; k <= n; ++k) if (ans % k == 0) {
      cout << k << ' ';
    }
    print();
  }
}