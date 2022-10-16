//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <vector>
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

constexpr int N = 3e5;
vector<int> ch[2][N];
int t[N][2], tc;
set<pair<int, int>> blocked;

void calc_t(int v) {
  t[v][0] = tc++;
  for (auto u: ch[1][v]) {
    calc_t(u);
  }
  t[v][1] = tc;
  ch[1][v].clear();
}

int ans;

void calc_ans(int v) {
  auto it = blocked.lower_bound(pair{t[v][0], 0});
  auto erased = pair{-1, -1};
  bool ni;
  if (ni = it != blocked.end() && it->first < t[v][1]) {
  } else {
    if (it != blocked.begin() && prev(it)->second >= t[v][1]) {
      erased = *--it;
      it = blocked.erase(it);
    }
    it = blocked.emplace_hint(it, t[v][0], t[v][1]);
  }
  maxi(ans, blocked.size());
  for (auto u: ch[0][v]) {
    calc_ans(u);
  }
  if (!ni) {
    it = blocked.lower_bound(pair{t[v][0], t[v][1]});
    it = blocked.erase(it);
    if (erased.first != -1) {
      blocked.insert(it, erased);
    }
  }
  ch[0][v].clear();
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
//  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $;
    for (auto c: {0, 1})
    for (int i = 1; i < n; ++i) {
      ch[c][$ - 1].push_back(i);
    }
    tc = ans = 0;
    blocked.clear();
    calc_t(0);
    calc_ans(0);
    print(ans);
  }
}