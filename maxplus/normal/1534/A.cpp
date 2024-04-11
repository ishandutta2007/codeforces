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
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } template <class T = string> T operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 50;
string s[N];
int n, m;

bool clr(int i, int j, bool force = 0) {
  bool f[2]{};
  for (auto di: {-1, 0, 1})
  for (auto dj: {-1, 0, 1}) if (!di != !dj && i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m) {
    f[0] |= s[i + di][j + dj] == 'R';
    f[1] |= s[i + di][j + dj] == 'W';
  }
  f[0] |= s[i][j] == 'W';
  f[1] |= s[i][j] == 'R';
  if (f[0] && f[1]) {
    return 0;
  } else if (s[i][j] != '.' || !f[0] && !f[1] && !force) {
    return 1;
  } else {
    bool ok = 1;
    s[i][j] = f[0]? 'W': 'R';
    for (auto di: {-1, 0, 1})
    for (auto dj: {-1, 0, 1}) if (!di != !dj && i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m) {
      ok &= clr(i + di, j + dj);
    }
    return ok;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    n = $, m = $;
    cin >> range{s, n};
    bool ok = 1;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      ok &= clr(i, j);
    }
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      ok &= clr(i, j, 1);
    }
    print(ok? "YES": "NO");
    if (ok) {
      for (auto& l: range{s, n}) {
        print(l);
      }
    }
  }
}