//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <vector>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } template <class T = string> T operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 1e5;
vector<int> nei[N][2];
bool vis[N];

struct Edge {
  int a, ab, ne;
  bool dir;
};

Edge edges[2 * N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, m = $, m0 = m;
  for (int i = 0; i < m; ++i) {
    int a = $ - 1, b = $ - 1, c = $ - 1;
    nei[a][c].push_back(i);
    nei[b][c].push_back(i);
    edges[i] = {a, a ^ b, -1, a > b};
  }
  for (auto _: {0, 1})
  for (int v = 0; v < n; ++v)
  for (auto c: {0, 1})
  while (1) {
    while (nei[v][c].size() && edges[nei[v][c].back()].ne != -1) {
      nei[v][c].pop_back();
    }
    if (nei[v][c].empty()) {
      break;
    }
    auto e0 = nei[v][c].back();
    nei[v][c].pop_back();
    while (nei[v][c].size() && edges[nei[v][c].back()].ne != -1) {
      nei[v][c].pop_back();
    }
    if (nei[v][c].empty()) {
      nei[v][c].push_back(e0);
      break;
    }
    auto e1 = nei[v][c].back();
    nei[v][c].pop_back();
    int a = edges[e0].ab ^ v;
    int b = edges[e1].ab ^ v;
    if (a == b) {
      edges[e0].dir ^= 1;
      edges[e0].ne = e0;
      edges[e1].ne = e1;
      continue;
    }
    edges[e0].ne = edges[e1].ne = m;
    nei[a][c].push_back(m);
    nei[b][c].push_back(m);
    edges[m++] = {a, a ^ b, -1, 0};
  }
  for (int i = 0; i < n; vis[i++] = 1)
  for (auto c: {0, 1}) if (int v = i, c0 = c; 1)
  while (nei[v][c].size()) {
    auto e = nei[v][c][0], u = v ^ edges[e].ab;
    if (!change(vis[u], 1)) {
      break;
    }
    edges[e].dir ^= (u < v) ^ c0;
    c ^= 1;
    v = u;
  }
  for (int i = m; i--; ) {
    if (edges[i].ne != -1 && edges[i].ne != i) {
      int a = edges[i].a, b = edges[i].ab ^ a;
      if (a == edges[edges[i].ne].a || a == (edges[edges[i].ne].a ^ edges[edges[i].ne].ab)) {
        swap(a, b);
      }
      int c = edges[edges[i].ne].ab ^ b;
      edges[i].dir ^= edges[edges[i].ne].dir ^ (b < a) ^ (b < c);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += nei[i][0].size() & 1;
  }
  print(ans);
  for (int i = 0; i < m0; ++i) {
    cout.put('1' + edges[i].dir);
  }
}