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
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 1e5;

int a[N], l[2][N], r[2][N], c[2][N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $;
  cin >> range{a, n};
  for (int i = 1; i < n; ++i) {
    bool cur = a[i] > a[i - 1];
    ++c[cur][l[cur][i] = l[cur][i - 1] + 1];
  }
  for (int i = n - 2; i > -1; --i) {
    bool cur = a[i] > a[i + 1];
    ++c[cur][r[cur][i] = r[cur][i + 1] + 1];
  }
  partial_sum(c[0], c[1], c[0]);
  partial_sum(c[1], c[2], c[1]);
  int ans = 0;
  for (int i = 1; i < n - 1; ++i) {
    ans += !(l[1][i] <= r[0][i + 1] || r[1][i] <= l[0][i - 1] || l[1][i] != r[1][i] || l[1][i] % 2 || c[0][l[1][i] - 1] < n - 3);
  }
  print(ans);
}