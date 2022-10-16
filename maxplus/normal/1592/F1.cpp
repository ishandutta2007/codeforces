#include <iostream>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} It begin() const { return first; } It end() const { return last; } };
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 501;

bool a[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, m = $, ans = 0, sub = 0;
  for (int i = 0; i < n; ++i)
  for (int j = 0; j < m; ++j) {
    a[i][j] = (char)$ == 'B';
  }
  for (int i = 0; i < n; ++i)
  for (int j = 0; j < m; ++j) {
    ans += a[i][j] ^= a[i + 1][j] ^ a[i][j + 1] ^ a[i + 1][j + 1];
  }
  for (int i = 0; i < n - 1; ++i)
  for (int j = 0; j < m - 1; ++j) {
    sub |= a[i][j] & a[i][m - 1] & a[n - 1][j] & a[n - 1][m - 1];
  }
  print(ans - sub);
}