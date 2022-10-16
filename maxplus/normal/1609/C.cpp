#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
//#pragma GCC optimize "tree-vectorize"
#include <algorithm>
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
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int P = 1e6 + 1, N = 2e5;

int d[P], a[2 * N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int i = 2; i < P; ++i) if (!d[i]) {
    ++d[i];
    for (int j = i * 2; j < P; j += i) {
      d[j] = 2;
    }
  }
  for (int testcase = $; testcase; --testcase) {
    int n = $, e = $;
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] = d[a[i]] + (i >= e? a[i - e]: 0);
    }
    for (int i = n + e - 1; i > -1; --i) {
      a[i] = i >= e? a[i - e]: 0;
    }
    for (int rem = 0; rem < e; ++rem) {
      int l = rem, r = rem, lr = rem;
      while (l < n) {
        while (lr < n + e && a[lr] == a[l]) {
          lr += e;
        }
        while (r < n + e && a[r] - a[l] <= 1) {
          r += e;
        }
        if (a[r - e] - a[l] == 1) {
          ans += unz((r - lr) / e - (lr == l + e));
        }
        l += e;
      }
    }
    print(ans);
  }
}