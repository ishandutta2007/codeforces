#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
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

constexpr int N = 100, K = 50, Q = 1000;

using Robots = array<int64_t, N>;
using Program = array<int64_t, K>;

Robots p;
Program prog[N];
array<int64_t, 2> qs[Q];
array<int64_t, 2> sqs[Q];
Robots hist[K];
int hists, histe, n, k, q;

Robots dst(const Robots& p) {
  Robots d{};
  for (int i = 1; i < n; ++i) {
    d[i - 1] = p[i] - p[i - 1];
  }
  return d;
}

void step(int tmod) {
  static int gp[N];
  int pw = prog[0][tmod], st = 0, st0 = 0, stm = 0, pwm = 0;
  for (int i = 1; i <= n; ++i) {
    auto breakgroup = [&](int st, int nd, int pw) {
      while (st < nd) {
        gp[st++] = pw;
      }
    };
    if (pw == 0) {
      st = i;
    } else if (pw < 0) {
      st0 = st = i;
      pwm += pw;
      pw = 0;
    }
    if (i == n || p[i - 1] < p[i] - 1) {
      breakgroup(stm, st0, pwm);
      breakgroup(st0, st, 0);
      breakgroup(st, i, pw);
      stm = st0 = st = i;
      pwm = pw = 0;
      if (i == n) {
        break;
      }
    }
    pw += prog[i][tmod];
  }
  for (int i = 1; i < n; ++i) {
    if (gp[i - 1] > 0 && gp[i] < 0 && p[i - 1] == p[i] - 2) {
      if (gp[i - 1] + gp[i] <= 0) {
        for (int j = i - 1; j > -1 && gp[j] > 0 && p[j] - j == p[i - 1] - i + 1; --j) {
          gp[j] = 0;
        }
      } else {
        for (int j = i; j < n && gp[j] < 0 && p[j] - j == p[i] - i; ++j) {
          gp[j] = 0;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    p[i] += (gp[i] > 0) - (gp[i] < 0);
  }
}

int64_t ffdur(const Robots& a, const Robots& b, int64_t res) {
  for (int i = 0; i < n - 1 && res; ++i) {
    if (b[i] > a[i] && a[i] + b[i] <= k) {
      res = 0;
    } else if (b[i] < a[i]) {
      mini(res, (b[i] - (k + 1 - (a[i] - b[i]) / 2)) / (a[i] - b[i]));
    }
  }
  return unz(res);
}

void solve() {
  for (int64_t t = 0, cq = 0; cq < q; ) {
    if (t == sqs[cq][0]) {
      qs[sqs[cq][1]][1] = p[qs[sqs[cq][1]][0]];
      ++cq;
      continue;
    }
    step(t % k);
    if (t++ && histe == hists) {
      auto ff = ffdur(dst(hist[hists]), dst(p), (sqs[cq][0] - t) / k);
      if (ff) {
        for (int i = 0; i < n; ++i) {
          p[i] += (p[i] - hist[hists][i]) * ff;
        }
        t += ff * k;
      } else {
        ++hists %= k;
      }
    }
    hist[histe] = p;
    ++histe %= k;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  cin >> n >> k;
  cin >> range{&p[0], n};
  for (int i = 0; i < n; ++i) {
    cin >> range{&prog[i][0], k};
  }
  cin >> q;
  for (int i = 0; i < q; ++i) {
    qs[i][0] = $ - 1;
    sqs[i] = {$, i};
  }
  sort(sqs, sqs + q);
  solve();
  for (int i = 0; i < q; ++i) {
    print(qs[i][1]);
  }
}