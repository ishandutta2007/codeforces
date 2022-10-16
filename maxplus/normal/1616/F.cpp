#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <optional>
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
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int M = 256, E = M + 1, mod = 3;

struct tritset {
  static constexpr int sz = E;

  int8_t a[sz];

  auto& operator[](int i) const { return a[i]; }
  auto& operator[](int i) { return a[i]; }

  auto& add(const tritset& oth, int start) {
    for (int i = start; i < sz; ++i) {
      a[i] += oth[i];
    }
    return *this;
  }

  auto& sub(const tritset& oth, int start) {
    for (int i = start; i < sz; ++i) {
      a[i] -= oth[i];
    }
    return *this;
  }

  auto& flip(int start) {
    for (int i = start; i < sz; ++i) {
      a[i] = -a[i];
    }
    return *this;
  }

  auto& normalize(int start) {
    for (int i = start; i < sz; ++i) {
      a[i] %= mod;
      if (a[i] == 1 - mod) {
        a[i] += mod;
      } else if (a[i] == mod - 1) {
        a[i] -= mod;
      }
    }
    return *this;
  }
};

vector<int> piv;
optional<tritset> gjelim(auto& sle) {
  constexpr int R = 126;
  piv.clear();
  tritset res{};
  for (int i = 0, skipped = 0; i < E; ++i) {
    int idx = i - skipped;
    while (idx < sle.size() && sle[idx][i] % mod == 0) {
      ++idx;
    }
    if (idx == sle.size()) {
      ++skipped;
      continue;
    }
    piv.push_back(i);
    swap(sle[idx], sle[i - skipped]);
    idx = i - skipped;
    sle[idx].normalize(i);
    if (sle[idx][i] != 1) {
      sle[idx].flip(i);
    }
    if (idx % R == 0)
    for (auto& le: range{sle.begin() + idx + 1, sle.end()}) {
      le.normalize(i);
    }
    for (auto& le: range{sle.begin() + idx + 1, sle.end()}) if (auto t = (le[i] + R) % mod) {
      t == 1? le.sub(sle[idx], i): le.add(sle[idx], i);
    }
  }
  if (piv.size() && piv.back() == M) {
    return {};
  }
  for (int i = piv.size(); i--; ) {
    int s = 0;
    for (auto j: range{piv.begin() + i + 1, piv.end()}) {
      s += sle[i][j] * res[j];
    }
    res[piv[i]] = ((sle[i][M] - s) % mod + mod) % mod;
  }
  return res;
}

constexpr int N = 64;

vector<pair<int, int>> edges;
bool adj[N][N];
int edgen[N][N];
vector<tritset> sle;

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  sle.reserve(1 << 12);
  edges.reserve(M);
  piv.reserve(M + 1);
  for (int testcase = $; testcase; --testcase) {
    int n = $, m = $;
    memset(adj, 0, sizeof adj);
    edges.clear();
    sle.clear();
    for (int i = 0; i < m; ++i) {
      int a = $ - 1, b = $ - 1, c = $ - 1;
      if (a < b) {
        swap(a, b);
      }
      edges.emplace_back(a, b);
      adj[a][b] = 1;
      edgen[a][b] = i;
      if (c >= 0) {
        sle.resize(sle.size() + 1);
        sle.back()[i] = 1;
        sle.back()[M] = c;
      }
    }
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < i; ++j) if (adj[i][j])
    for (int k = 0; k < j; ++k) if (adj[i][k] && adj[j][k]) {
      sle.resize(sle.size() + 1);
      sle.back()[edgen[i][j]] = sle.back()[edgen[i][k]] = sle.back()[edgen[j][k]] = 1;
    }
    if (auto sol = gjelim(sle)) {
      for (int i = 0; i < m; ++i) {
        cout << 1 + sol->a[i] << ' ';
      }
      print();
    } else {
      print(-1);
    }
  }
}