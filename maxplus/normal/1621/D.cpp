//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } string operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 500;
int a[N][N], n;
//int dst[N][N];
//
//int64_t dijkstra(int dr, int dc) {
//  priority_queue<pair<int64_t, pair<int, int>>> q;
//  for (int i = 0; i < n; ++i)
//  for (int j = 0; j < n; ++j) {
//    q.push({0, {i, j}});
//    dst[i][j] = 0;
//  }
//  while (!q.empty()) {
//    auto [d, coord] = q.front(); auto [r, c] = coord; q.pop();
//    {
//      int nr = r + dr, nc = c;
//      if (nr == 2 * n) {
//        nr -= 2 * n;
//      } else if (nr < 0) {
//        nr += 2 * n;
//      }
//      if (minb(dst))
//  }
//}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    n = $;
    for (int i = 0; i < 2 * n; ++i) {
      cin >> range{a[i], 2 * n};
    }
//    for (int r = 0; r < 2 * n; ++r)
//    for (int c = 0; c < 2 * n; ++c)
    int ans0 = 2e9;
    for (int x: {0, n})
    for (int y: {0, n - 1})
    for (int z: {0, n - 1}) {
      mini(ans0, a[x + y][n - x + z]);
    }
    int64_t ans = ans0;
    for (int i = n; i < 2 * n; ++i)
    for (int j = n; j < 2 * n; ++j) {
      ans += a[i][j];
    }
    print(ans);
  }
}