//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <stack>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } string operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int mod = 1e9 + 7, N = 3e5 + 1, L = 19;
const int base = __builtin_ia32_rdtsc() % mod;

int bp[L];
int par[N][L], h[N][L];
int len[N], first[N];

int mul(int a, int b) {
  return a * (int64_t)b % mod;
}

int add(int a, int b) {
  return (a += b) < mod? a: a - mod;
}

bool cmp(int i, int j) {
  int mile = min(len[i], len[j]);
  for (int l = L; l--; ) if ((1 << l) <= mile && h[i][l] == h[j][l]) {
    i = par[i][l], j = par[j][l];
    mile -= 1 << l;
  }
  return mile? h[i][0] < h[j][0]: i > j;
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int i = 0, cp = base; i < L; ++i) {
    bp[i] = cp;
    cp = mul(cp, cp);
  }
  string s = $;
  first[s.size()] = s.size();
  stack<int> rb;
  for (int i = s.size(); i--; ) {
    first[i] = i;
    len[i] = len[i + 1] + 1;
    par[i][0] = first[i + 1];
    h[i][0] = s[i] - '(';
    for (int l = 1; l < L && (1 << l) <= len[i]; ++l) {
      par[i][l] = par[par[i][l - 1]][l - 1];
      h[i][l] = add(mul(h[i][l - 1], bp[l - 1]), h[par[i][l - 1]][l - 1]);
    }
    if (s[i] == ')') {
      rb.push(i);
    } else if (rb.size()) if (auto match = rb.top(); rb.pop(), cmp(match + 1, i)) {
      first[i] = first[match + 1];
      len[i] = len[match + 1];
      memcpy(par[i], par[match + 1], sizeof par[i]);
      memcpy(h[i], h[match + 1], sizeof h[i]);
    }
  }
  for (int i = 0; i < s.size(); i = par[i][0]) {
    cout.put('(' + h[first[i]][0]);
  }
}