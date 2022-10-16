#include <iostream>
#include <numeric>
#include <vector>
#include <array>

#include <cstdio>
struct UnsafeInput {
  static constexpr int bufsz = 1 << 15;

  UnsafeInput() {
    read();
  }

  void read() {
    fread(buf + 1, 1, sizeof buf - 1, stdin);
    bufptr = buf;
  }

  template <typename T>
  void operator()(T* b, size_t n) {
    for (size_t i = 0; i < n; ++i) {
      b[i] = {};
    }
    (*this)(b, b + n);
  }

  template <typename ...Ts>
  auto operator()(Ts&... xs) -> std::enable_if_t<(!std::is_pointer_v<std::decay_t<Ts>> && ...)> {
    ((*this)(&(xs = {}), &xs + 1), ...);
  }

  char buf[bufsz], *bufptr = buf;
private:

  template <typename T>
  void operator()(T* b, T* e) {
    bool sign = 0;
    while (b != e) {
      if (++bufptr == buf + bufsz) {
        read();
      } else if (*bufptr == '-') {
        sign = 1;
      } else if (*bufptr < '0') {
        *b++ *= sign? -1: 1, sign = 0;
      } else {
        *b = *b * 10 + *bufptr - '0';
      }
    }
  }
} reader;

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; reader(t); return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
auto print(const auto& c) -> decltype(c.begin(), void()) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 3e5 + 1;

vector<int> nei[N];
array<int, 2> queries[N];
int qdg[N];
int p[N], d[N];

void dfs(int v) {
  for (auto u: nei[v]) if (!p[u]) {
    d[u] = d[p[u] = v] + 1;
    dfs(u);
  }
}

int main() {
  int n = $, m = $;
  while (m--) {
    int a = $, b = $;
    nei[a].push_back(b);
    nei[b].push_back(a);
  }
  int q = $;
  reader(&queries[0][0], 2 * q);
  for (auto& c: range{&queries[0][0], 2 * q}) {
    qdg[c] ^= 1;
  }
  if (int badv = accumulate(qdg + 1, qdg + 1 + n, 0)) {
    print("NO");
    print(badv / 2);
  } else {
    print("YES");
    dfs(p[1] = 1);
    vector<int> pref, suf;
    for (const auto& c: range{queries, q}) {
      pref = {c[0]}, suf = {c[1]};
      while (pref.back() != suf.back()) {
        if (d[pref.back()] > d[suf.back()]) {
          pref.push_back(p[pref.back()]);
        } else {
          suf.push_back(p[suf.back()]);
        }
      }
      print(pref.size() + suf.size() - 1, pref, range{suf.rbegin() + 1, suf.rend()});
    }
  }
}