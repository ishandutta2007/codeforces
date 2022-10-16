#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
//#pragma GCC optimize "tree-vectorize"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <array>

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

constexpr int N = 1e3 + 1;

#include <utility>
struct DSU {
  static constexpr int N = ::N;

  DSU() {
    for (int i = 0; i < N; ++i) {
      p[i] = i;
      w[i] = 1;
    }
  }

  auto operator[](int v) { return w[getp(v)]; }
  auto operator[](pair<int, int> vu) { return getp(vu.first) == getp(vu.second); }
  auto operator()(int v) { return getp(v); }
  auto operator()(int v, int u) { return uni(v, u); }

private:
  int p[N], w[N];

  int getp(int v) {
    return p[v] == v? v: p[v] = getp(p[v]);
  }

  void uni(int u, int v) {
    if (w[v = getp(v)] > w[u = getp(u)]) {
      swap(u, v);
    }
    p[v] = u;
    w[u] += w[v];
  }
};

array<int, 2> c[N];
int szs[N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, d = $;
  cin >> range{c, d};
  for (int i = 0; i < d; ++i) {
    DSU dsu{};
    int ans = 0, extra = 0;
    for (int j = 0; j <= i; ++j) {
      auto [a, b] = c[j];
      if (dsu[{a, b}]) {
        ++extra;
      } else {
        dsu(a, b);
      }
    }
    for (int j = 1; j <= n; ++j) {
      szs[j - 1] = dsu(j) == j? dsu[j]: 0;
    }
    nth_element(szs, szs + n - extra - 1, szs + n);
    print(accumulate(szs + n - extra - 1, szs + n, -1));
  }
}