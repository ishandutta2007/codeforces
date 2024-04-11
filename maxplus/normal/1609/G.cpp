//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <numeric>
#include <array>

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

constexpr int S = 1 << 17, N = 100, M = 1e5;

int64_t t[2 * S][2], a[N], da[N], b[M], pb[N][2];

int midl(int l, int r) {
  int step = 1 << 31 - __builtin_clz(r - l);
  return min(l + step, r - step / 2);
}

void build(int i, int L, int R) {
  t[i][0] += b[L];
  auto d = L? b[L] - b[L - 1]: 0;
  t[i][1] += d;
  if (R == L + 1) {
    return;
  }
  int M = midl(L, R);
  t[2 * i + 1][0] -= b[L];
  t[2 * i + 1][1] -= d;
  t[2 * i + 2][0] -= b[L] + d * (M - L);
  t[2 * i + 2][1] -= d;
  build(2 * i + 1, L, M);
  build(2 * i + 2, M, R);
}

void update(int i, int L, int R, int l, int d) {
  if (R <= l + 1) {
    return;
  } else if (L > l) {
    t[i][0] += d * int64_t(L - l);
    t[i][1] += d;
    return;
  }
  int M = midl(L, R);
  update(2 * i + 1, L, M, l, d);
  update(2 * i + 2, M, R, l, d);
}

template <bool oneleft=0>
void look(int i, int L, int R, int l, int r, array<int64_t, 2> b) {
  while (R != L + 1) {
    b[0] += t[i][0];
    b[1] += t[i][1];
    int M = midl(L, R);
    if (auto tmp = t[2 * i + 2][1] + b[1]; tmp <= da[l]) {
      b[0] += b[1] * (M - L);
      L = M;
      i = 2 * i + 2;
    } else {
      if constexpr (!oneleft) {
        if (tmp < da[r - 1]) {
          int m = l + 1;
          while (tmp >= da[m]) {
            ++m;;
          }
          auto tb = b;
          tb[0] += b[1] * (M - L);
          if (m == r - 1) {
            look<1>(2 * i + 2, M, R, m, r, tb);
          } else {
            look(2 * i + 2, M, R, m, r, tb);
          }
          r = m;
        }
      }
      R = M;
      i = 2 * i + 1;
    }
  }
  pb[l][0] = L;
  pb[l][1] = b[0] += t[i][0];
  if constexpr (!oneleft)
  for (int j = l + 1; j < r; ++j) {
    pb[j][0] = L;
    pb[j][1] = b[0];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, m = $, q = $;
  cin >> range{a, n} >> range{b, m};
  build(0, 0, m);
  int64_t sb = accumulate(b + 1, b + m, *b);
  adjacent_difference(a, a + n, da);
  while (q--) {
    {
      int t = $, k = $ + 1, d = $;
      if (t == 1) {
        k = n - k;
        for (int i = k + 1; i < n; ++i) {
          a[i] += int64_t(i - k) * d;
          da[i] += d;
        }
      } else {
        update(0, 0, m, m - k, d);
        sb += d * k * (k - 1ll) / 2;
      }
    }
    int64_t ans = sb + a[0] * (n + m - 1) + b[0] * (n - 1), lb = b[0];
    look(0, 0, m, 1, n, {});
    for (int i = 1; i < n; ++i) {
      auto [p, b] = pb[i];
      ans += int64_t(n + m - i - p - 1) * da[i] + (n - i) * change(lb, b);
    }
    print(ans);
  }
}