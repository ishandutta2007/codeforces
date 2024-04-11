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
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 1e5 + 1;
int64_t mod = 1'000'000'000 + 7, base = 37;

string s, rs;
int64_t h[N], rh[N], pbase[2 * N];
int n;

int64_t hshfirst(int i, int k) {
  if (k <= i) {
    return h[k];
  }
  int64_t res = h[i];
  k -= i;
  mini(k, i);
  auto st = n - i, ed = st + k;
  res = (res * pbase[k] + rh[ed] - rh[st] * pbase[k]) % mod;
  if (res < 0) {
    res += mod;
  }
  return res;
}

bool cmp(int i, int j) {
  if (i > j) {
    return !cmp(j, i);
  }
  int l = i, r = 2 * i + 1;
  while (r > l + 1) {
    int m = (l + r) / 2;
    if (hshfirst(i, m) == hshfirst(j, m)) {
      l = m;
    } else {
      r = m;
    }
  }
  if (l == 2 * i) {
    return i < j;
  } else {
    return s[2 * i - l - 1] < (l < j? s[l]: s[2 * j - l - 1]);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int64_t i = 0, cp = 1; i < 2 * N; ++i) {
    pbase[i] = cp;
    (cp *= base) %= mod;
  }
  for (int testcase = $; testcase; --testcase) {
    cin >> n >> s;
    rs = string(s.rbegin(), s.rend());
    for (int64_t i = 0, ch = 0; i <= n; ++i) {
      h[i] = ch;
      if (i != n) {
        ((ch *= base) += s[i] - '`') %= mod;
      }
    }
    for (int64_t i = 0, ch = 0; i <= n; ++i) {
      rh[i] = ch;
      if (i != n) {
        ((ch *= base) += rs[i] - '`') %= mod;
      }
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i) if (!cmp(ans, i)) {
      ans = i;
    }
    print(s.substr(0, ans) + string(s.rend() - ans, s.rend()));
  }
}