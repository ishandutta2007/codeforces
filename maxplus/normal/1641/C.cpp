//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <set>

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

constexpr int N = 2e5;

int p[N], w[N], r[N];
set<int> s;

int getp(int v) { return p[v] == v? v: p[v] = getp(p[v]); }

void uni(int u, int v) {
  if (w[u = getp(u)] < w[v = getp(v)]) {
    swap(u, v);
  }
  if (u == v) {
    return;
  }
  mini(r[u], r[v]);
  w[u] += w[v];
  p[v] = u;
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, q = $;
  for (int i = 0; i < n; ++i) {
    s.insert(s.end(), i);
    p[i] = i;
    w[i] = 1;
    r[i] = n + 1;
  }
  while (q--) {
    if ($) {
      int j = $ - 1;
      auto it = s.find(j);
      if (it == s.end()) {
        print("NO");
        continue;
      }
      int rsick = r[j];
      if (it == s.begin() || *prev(it) != j - 1) {
        mini(rsick, r[getp(unz(j - 1))]);
      }
      print(rsick > n || ++it != s.end() && *it < rsick? "N/A": "YES");
    } else if (int l = $ - 1, r = $, x = $; x) {
      mini(::r[getp(l)], r);
    } else {
      auto it = s.lower_bound(l);
      if (it == s.begin() || *prev(it) != l - 1) {
        uni(l, unz(l - 1));
      }
      for (; it != s.end() && *it < r; ) {
        uni(l, *it);
        it = s.erase(it);
      }
      if (it == s.end() || *it != r) {
        uni(l, min(n - 1, r));
      }
    }
  }
}