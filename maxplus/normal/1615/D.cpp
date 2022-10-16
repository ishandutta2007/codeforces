//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <vector>
#include <array>
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
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 2e5;

vector<array<int, 3>> edges;
vector<pair<int, bool>> nei[N];
bool vis[N], p[N], ok;

void colour(int v, bool c) {
  if (change(vis[v], 1)) {
    p[v] = c;
  } else {
    ok &= p[v] == c;
    return;
  }
  for (auto [u, x]: nei[v]) {
    colour(u, c ^ x);
  }
  nei[v].clear();
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $, m = $;
    edges.clear();
    memset(vis, 0, sizeof vis);
    memset(p, 0, sizeof p);
    ok = 1;
    for (int i = -n + 1; i < m; ++i) {
      int a = $ - 1, b = $ - 1, v = $;
      if (v != -1) {
        nei[a].emplace_back(b, __builtin_parity(v));
        nei[b].emplace_back(a, __builtin_parity(v));
      }
      if (i < 0) {
        edges.emplace_back(array{a, b, v});
      }
    }
    for (int i = 0; i < n; ++i) {
      colour(i, p[i]);
    }
    if (!ok) {
      print("NO");
      continue;
    }
    print("YES");
    for (auto [u, v, c]: edges) {
      print(u + 1, v + 1, c == -1? p[u] ^ p[v]: c);
    }
  }
}