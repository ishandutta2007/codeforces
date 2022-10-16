//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <vector>
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

constexpr int N = 1e5;

int n;

struct FT {
  using T = int;
  static constexpr int N = ::N;

  T& op(T& val, const T& arg) {
    return val += arg;
  }

  void build() {
    for (int i = 0; i < n; ++i) if ((i | (i + 1)) < n) {
      op(ft[i | (i + 1)], ft[i]);
    }
  }

  void update(int i, T val = 1) {
    for (; i < n; i |= i + 1) {
      op(ft[i], val);
    }
  }

  T query(int i) {
    T res{};
    for (; i; i &= i - 1) {
      op(res, ft[i - 1]);
    }
    return res;
  }

  void rupdate(int i, T val = 1) { return update(n - i - 1, val); }

  T rquery(int i) { return query(n - 1 - i); }

private:
  T ft[N];
} ft;

constexpr int A = 26;
vector<int> loc[A];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
//  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    n = $;
    string s = $, t = $;
    memset(&ft, 0, n * sizeof n);
    for (auto& x: loc) {
      x.clear();
    }
    for (int i = 0; i < n; ++i) {
      loc[s[i] - 'a'].push_back(i);
    }
    for (auto& x: loc) {
      reverse(x.begin(), x.end());
    }
    uint64_t ans = -1ull, cans = 0;
    for (int i = 0; i < n; ++i) {
      int c = t[i] - 'a';
      int mipo = 2 * n;
      for (int j = 0; j < c; ++j) if (!loc[j].empty()) {
        mini(mipo, loc[j].back());
      }
      if (mipo != 2 * n) {
        mini(ans, cans + mipo + ft.rquery(mipo) - i);
      }
      if (loc[c].empty()) {
        break;
      }
      mipo = loc[c].back();
      loc[c].pop_back();
      cans += mipo + ft.rquery(mipo) - i;
      ft.rupdate(mipo);
    }
    print((int64_t)ans);
  }
}