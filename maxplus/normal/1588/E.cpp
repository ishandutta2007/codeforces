#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,lzcnt,abm"
#include <iostream>
#include <algorithm>

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

template <typename T>
struct ArithmeticOperators {
  template <typename LowPriority = void>
  constexpr friend T operator+(T lhs, const T& rhs) { return lhs += rhs; }
  template <typename LowPriority = void>
  constexpr friend T& operator-=(T& lhs, const T& rhs) { return lhs += -rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator-(T lhs, const T& rhs) { return lhs -= rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator*(T lhs, const T& rhs) { return lhs *= rhs; }
  template <typename LowPriority = void>
  constexpr friend T& operator/=(T& lhs, const T& rhs) { return lhs *= ~rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator/(T lhs, const T& rhs) { return lhs /= rhs; }
};

struct Point : ArithmeticOperators<Point> {
  int x, y;

  explicit constexpr Point(int x = 0, int y = 0) : x(x), y(y) {}

  friend auto& operator>>(istream& in, Point& self) { return in >> self.x >> self.y; }
  friend auto& operator<<(ostream& out, const Point& self) { return out << self.x << ' ' << self.y; }
  constexpr auto operator-() { return Point{-x, -y}; }
  constexpr auto& operator-=(const Point& oth) { x -= oth.x; y -= oth.y; return *this; }
  constexpr auto& operator+=(const Point& oth) { x += oth.x; y += oth.y; return *this; }
  constexpr friend auto rot90(const Point& arg) { return Point{-arg.y, arg.x}; }
  constexpr friend auto cp(const Point& lhs, const Point& rhs) { return lhs.x * int64_t(rhs.y) - lhs.y * int64_t(rhs.x); }
  constexpr friend auto cp(const Point& lhs, const Point& piv, const Point& rhs) { return cp(lhs - piv, rhs - piv); }
  constexpr friend auto dp(const Point& lhs, const Point& rhs) { return lhs.x * int64_t(rhs.x) + lhs.y * int64_t(rhs.y); }
  constexpr friend auto dp(const Point& lhs, const Point& piv, const Point& rhs) { return dp(lhs - piv, rhs - piv); }
  constexpr friend auto sq(const Point& arg) { return dp(arg, arg); }

  struct XYCmp { constexpr bool operator()(const Point& lhs, const Point& rhs) const { return pair{lhs.x, lhs.y} < pair{rhs.x, rhs.y}; } };
  struct YXCmp { constexpr bool operator()(const Point& lhs, const Point& rhs) const { return pair{lhs.y, lhs.x} < pair{rhs.y, rhs.x}; } };
  constexpr friend auto polarcmp(const Point& piv) {
    return [piv](const Point& lhs, const Point& rhs) { auto t = cp(lhs, piv, rhs); return t != 0? t > 0: sq(lhs - piv) < sq(rhs - piv); };
  }

  static auto convex_hull(auto first, auto last, auto dst, bool minimal) {
    auto piv = *min_element(first, last, YXCmp{});
    sort(first, last, polarcmp(piv));
    if (!minimal) {
      auto it = last - 1;
      while (it >= first && !cp(*it--, piv, *prev(last)));
      reverse(it + 1, last);
    }
    auto w = dst;
    for (auto it = first; it != last; *w++ = *it++)
    for (int64_t t = 0; w - dst >= 2 && (t = cp(*(w - 2), *prev(w), *it), minimal? t >= 0: t > 0); ) {
      --w;
    }
    return w;
  }
};

constexpr int N = 3e3;

bool check_rrsqd_ge_cc_fp(int r, int64_t sqd, int64_t c) {
  auto t = (float)c / r;
  return sqd >= t * t;
}

bool check_rrsqd_ge_cc_fp_nodiv(int r, int64_t sqd, int64_t c) {
  return sqd * r * float(r) >= c * float(c);
}

bool check_rrsqd_ge_cc(int r, int64_t sqd, int64_t c) {
  c = llabs(c);
  auto rat = c / r, rem = c % r, sqr = r * int64_t(r);
  if (rat >= 3e5) {
    return 0;
  }
  auto lhsceil = rat * rat + (rem * (rem + 2 * rat * r) + sqr - 1) / sqr;
  return lhsceil <= sqd;
}

bool inangle(int r, const Point& a, const Point& t) {
  if (__builtin_expect(dp(a, t) <= 0, 0)) {
    return 0;
  }
  int64_t sqd = sq(t), c = cp(a, t);
  return check_rrsqd_ge_cc_fp(r, sqd, c);
}

bool inangle(int r, const Point& a, const Point& t, int64_t sqd) {
  if (__builtin_expect(dp(a, t) <= 0, 0)) {
    return 0;
  }
  return check_rrsqd_ge_cc_fp(r, sqd, cp(a, t));
}

bool angle_cmp(int r, const Point& a, const Point& b, bool dir, int64_t c, int64_t sqda, int64_t sqdb, int64_t d) {
  if (__builtin_expect(!c, 0)) {
    return sqda < sqdb;
  } else if (auto ordphi = (c > 0) == dir, ordrho = sqda < sqdb; ordphi == ordrho || __builtin_expect(sqda == sqdb, 0)) {
    return ordphi;
  } else {
    return (d > (ordrho? sqda: sqdb) && check_rrsqd_ge_cc_fp(r, sq(a - b), c)) == ordrho;
  }
}

Point p[N], l[N], r[N];
bool bad[N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, dst = $;
  auto sqdst = dst * int64_t(dst);
  cin >> range{p, n};
  int ans = 0;
  random_shuffle(p, p + n);
  for (int i = 0; i < n; ++i) {
    int k = -1;
    while (++k < n && sq(p[k] - p[i]) <= sqdst);
    if (k == n) {
      ans += n - i - 1;
      bad[i] = 1;
      continue;
    }
    Point l = p[k++] - p[i], r = l;
    auto sqdl = sq(l), sqdr = sqdl;
    bool ok = 1;
    for (; k < n && ok; ++k) if (auto sk = p[k] - p[i]; sq(sk) > sqdst) {
      auto cl = cp(sk, l), cr = cp(sk, r), sqdk = sq(sk), dl = dp(sk, l), dr = dp(sk, r);
      if (__builtin_expect(cl == 0, 0)) {
        ok &= dl > 0;
      } else if (__builtin_expect(cr == 0, 0)) {
        ok &= dr > 0;
      } else {
        ok &= cl > 0 || cr < 0;
      }
      if (angle_cmp(dst, l, sk, 0, cl, sqdl, sqdk, dl)) {
        l = sk;
        sqdl = sqdk;
      }
      if (angle_cmp(dst, r, sk, 1, cr, sqdr, sqdk, dr)) {
        r = sk;
        sqdr = sqdk;
      }
    }
    ::l[i] = l, ::r[i] = r;
    if (!ok) {
      bad[i] = 1;
      continue;
    }
  }
  for (int i = 0; i < n; ++i) if (!bad[i])
  for (int j = i + 1; j < n; ++j) if (!bad[j]) {
    auto sj = p[j] - p[i];
    auto si = -sj;
    auto sqd = sq(sj);
    ans += inangle(dst, l[i], sj, sqd) && inangle(dst, r[i], sj, sqd) &&
           inangle(dst, l[j], si, sqd) && inangle(dst, r[j], si, sqd);
  }
  cout << ans;
}