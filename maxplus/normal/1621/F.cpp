//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
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

//constexpr int N = ;
//int a[N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
//  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $, a = $, b = $, c = $;
    string s = ~$;
    int p0{}, p1{}, g1{};
    vector<int> g0;
    for (int i = 0, lst = -1; i < n; ++i) {
      if (s[i] == '0') {
        if (i && s[i - 1] == '0') {
          ++p0;
        } else {
          lst = i;
        }
      } else if (i && s[i - 1] == '1') {
        ++p1;
      } else {
        ++g1;
        if (lst > 0) {
          g0.push_back(i - lst - 1);
        }
      }
    }
    int64_t ans = min(p0, p1 + 1) * int64_t(a) + min(p1, p0 + 1) * int64_t(b);
    sort(g0.rbegin(), g0.rend());
    int st0 = s.find('1'), ed0 = n - 1 - s.rfind('1'), emp{};
    while (g0.size() && g0.back() == 0) {
      g0.pop_back();
      ++emp;
    }
    for (auto ord: {0, 1}) {
      int64_t cans = 0;
      int cst = st0, ced = ed0, ce = emp, cp = p1;
      auto cg0 = g0;
      while (1) {
        if (ord) {
          if (cp--) {
            cans += b;
          } else {
            break;
          }
        } else {
          if (!cp && ce) {
            --ce;
            cans -= c;
            ++cp;
          } else if (cg0.size()) {
            if (!--cg0.back()) {
              cg0.pop_back();
              ++ce;
            }
            cans += a;
          } else if (cst > 1) {
            --cst;
            cans += a;
          } else if (ced > 1) {
            --ced;
            cans += a;
          } else if (ce) {
            --ce;
            cans -= c;
            ++cp;
          } else if (cp && cst) {
            --cst;
            cans -= c;
          } else if (cp && ced) {
            --ced;
            cans -= c;
          } else {
            break;
          }
        }
        ord ^= 1;
      }
      maxi(ans, cans);
    }
    print(ans);
  }
}