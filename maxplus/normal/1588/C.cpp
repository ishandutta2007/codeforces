#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,lzcnt,abm"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

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

constexpr int N = 3e5, L = 19;

int64_t sptmi[L][N], sptma[L][N], a[N];
map<int64_t, vector<int>> occ;

void calc_spt(int n) {
  for (int l = 1; l < L; ++l) {
    int step = 1 << l - 1, left = unz(n - step), len = n - left;
    for (int64_t* p00 = sptmi[l - 1], * p0 = sptmi[l - 1] + step, * p1 = sptmi[l], * p2 = sptmi[l] + n - step; p1 < p2; ++p1, ++p0, ++p00) {
      *p1 = min(*p00, *p0);
    }
    memcpy(sptmi[l] + left, sptmi[l - 1] + left, len * sizeof **sptmi);
    for (int64_t* p00 = sptma[l - 1], * p0 = sptma[l - 1] + step, * p1 = sptma[l], * p2 = sptma[l] + n - step; p1 < p2; ++p1, ++p0, ++p00) {
      *p1 = max(*p00, *p0);
    }
    memcpy(sptma[l] + left, sptma[l - 1] + left, len * sizeof **sptmi);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
//  ios::sync_with_stdio(0);
  memset(sptmi, 63, sizeof sptmi);
  memset(sptma, 191, sizeof sptma);
  for (int testcase = $; testcase; --testcase) {
    int n = $;
    occ.clear();
    for (int i = 0; i < n; ++i) {
      a[i] = i & 1? -$: $;
      if (i) {
        a[i] += a[i - 1];
      }
      (i & 1? sptma: sptmi)[0][i] = a[i];
      occ[a[i]].push_back(i);
    }
    calc_spt(n);
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
      int j = i, t = i & 1;
      int64_t prv = i? a[i - 1]: 0;
      for (int l = L - 1; l > -1 && j != n; --l) {
        if (sptmi[l][j] >= prv && prv >= sptma[l][j]) {
          j = min(j + (1 << l), n);
        }
      }
      auto& v = occ[prv];
      ans += lower_bound(v.begin(), v.end(), j) - lower_bound(v.begin(), v.end(), i);
    }
    print(ans);
  }
}