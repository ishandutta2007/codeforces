#include <iostream>
#include <cstring>

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
auto operator>>(istream& in, auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 501;
int n, m;
bool a[N][N], used[N];
int p[N];

bool try_kuhn(int r) {
  if (used[r]) {
    return 0;
  }
  used[r] = 1;
  for (auto t: {0, 1})
  for (int c = 0; c < m - 1; ++c) if (a[r][c] && a[r][m - 1] && a[n - 1][c] && (t? try_kuhn(p[c]): p[c] == -1)) {
    p[c] = r;
    return 1;
  }
  return 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int ans = 0, sub = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
  for (int j = 0; j < m; ++j) {
    a[i][j] = (char)$ == 'B';
  }
  for (int i = 0; i < n; ++i)
  for (int j = 0; j < m; ++j) {
    ans += a[i][j] ^= a[i][j + 1] ^ a[i + 1][j] ^ a[i + 1][j + 1];
  }
  memset(p, -1, sizeof p);
  for (int i = 0; i < n - 1; ++i) {
    sub += try_kuhn(i);
    memset(used, 0, sizeof used);
  }
  cout << ans - sub + sub % 2 * (1 - a[n - 1][m - 1] * 2);
}