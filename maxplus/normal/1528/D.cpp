//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <deque>
#include <queue>
#include <cstring>

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

constexpr int N = 600;
int dst[N], n, m;

struct Edge {
  bool ex;
  int c;
};

Edge e[N][N];

int ans[N][N];

priority_queue<pair<int, int>> q;

void dijkstra(int v) {
  memset(dst, 127, sizeof dst);
  dst[v] = 0;
  q.emplace(dst[v], v);
  while (!q.empty()) {
    auto [d, v] = q.top(); q.pop();
    d = -d;
    if (dst[v] != d) {
      continue;
    }
    for (int i = 0; i < n; ++i) if (e[v][i].ex) {
      for (int j = 0; !j || !e[v][(i + j) % n].ex; ++j) {
        int cd = d + j, u = (i + cd) % n;
        if (minb(dst[u], cd + e[v][i].c)) {
          q.emplace(-dst[u], u);
        }
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  n = $, m = $;
  memset(e, 0, sizeof e);
  for (int i = 0; i < m; ++i) {
    int a = $, b = $;
    e[a][b].ex = 1;
    e[a][b].c = $;
  }
  for (int i = 0; i < n; ++i) {
    deque<pair<int, int>> ce;
    for (int j = 0; j < n; ++j) if (e[i][j].ex) {
      if (ce.empty() || ce.back().second + j - ce.back().first > e[i][j].c) {
        ce.emplace_back(j, e[i][j].c);
      }
    }
    while (ce.size() > 1 && ce.back().second + n + (ce.front().first - ce.back().first) < ce.front().second) {
      ce.pop_front();
    }
    memset(e[i], 0, sizeof e[i]);
    for (auto [j, c]: ce) {
      e[i][j].ex = 1, e[i][j].c = c;
    }
  }
  for (int i = 0; i < n; ++i) {
    dijkstra(i);
    print(range{dst, n});
  }
}