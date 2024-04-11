//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <vector>

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
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 2e5, S = 2 * N - 1;

template <typename Tag = int, typename Val = int> struct TaggedValue {
  Val val; Tag tag; constexpr TaggedValue(const Val& val = {}, const Tag& tag = {}) : val{val}, tag{tag} { } constexpr bool operator==(const TaggedValue& oth) const { return val == oth.val; } constexpr bool operator<(const TaggedValue& oth) const { return val < oth.val; } TaggedValue operator+(Val arg) {auto res = *this; res.val += arg; return res;} }; using Tagged = TaggedValue<>;

int h[S];
Tagged t[S];

int midl(int l, int r) {
  int step = (1 << 31 - __builtin_clz(r - l));
  return min(l + step, r - step / 2);
}

int depth[N];
enum STOTag {BUILD, MODIFY, QUERY};

struct STOperation {
  using T = Tagged;
  using S = int;

  STOTag q;
  int l, r;
  S arg;

  T call(int i = 0, int L = 0, int R = N) {
    T dummy{}, &maybe = q == QUERY? dummy: t[i];
    if (r <= L || R <= l) {
      return maybe + h[i];
    }
    if (q == BUILD? R == L + 1: l <= L && R <= r) {
      if (q == MODIFY) {
        apply(i, arg);
      } else if (q == BUILD) {
        t[i] = {depth[L], L};
      }
      return t[i] + h[i];
    }
    int M = midl(L, R);
    return (maybe = max(call(2 * i + 1, L, M), call(2 * i + 2, M, R))) + h[i];
  }

  int apply(int i, S val) {
    h[i] += val;
    return i;
  }
};;

int tin[N], tout[N], tcur, par[N], in2v[N];
vector<int> nei[N];
int n;

void build(int v, int p = -1, int d = 1) {
  depth[tcur] = d;
  in2v[tin[v] = tcur++] = v;
  par[v] = p;
  for (auto u: nei[v]) if (u != p) {
    build(u, v, d + 1);
  }
  tout[v] = tcur;
}

bool white[N];
int w = 0;

int64_t calc_score(int r) {
  int mindif = r - (n - r - w);
  int targdif = (n - 2 * r) / 2;
  if (mindif >= 0 || mindif >= -targdif) {
    return mindif * (int64_t)w;
  } else {
    return targdif * -int64_t(n - 2 * r - targdif);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  n = $;
  int k = $;
  for (int i = 1; i < n; ++i) {
    int a = $ - 1, b = $ - 1;
    nei[a].push_back(b);
    nei[b].push_back(a);
  }
  build(0);
  STOperation{BUILD, 0, n}.call(0, 0, n);
  int64_t ans = -1e18;
  for (int r = 0; maxi(ans, calc_score(r)), r < k; ++r) {
    auto [d, in] = STOperation{QUERY, 0, n}.call(0, 0, n);
    if (d == 0) {
      --w;
      continue;
    }
    int v = in2v[in];
    while (v != -1 && !white[v]) {
      STOperation{MODIFY, tin[v], tout[v], -1}.call(0, 0, n);
      if (v != in2v[in]) {
        w += white[v] = 1;
      }
      v = par[v];
    }
  }
  print(ans);
}