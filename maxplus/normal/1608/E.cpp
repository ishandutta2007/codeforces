//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <array>

#include <cstdio>
struct UnsafeInput {
  static constexpr int bufsz = 1 << 15;

  UnsafeInput() {
    read();
  }

  void read() {
    fread(buf + 1, 1, sizeof buf - 1, stdin);
    bufptr = buf;
  }

  template <typename T>
  void operator()(T* b, size_t n) {
    for (size_t i = 0; i < n; ++i) {
      b[i] = {};
    }
    (*this)(b, b + n);
  }

  template <typename ...Ts>
  auto operator()(Ts&... xs) -> std::enable_if_t<(!std::is_pointer_v<std::decay_t<Ts>> && ...)> {
    ((*this)(&(xs = {}), &xs + 1), ...);
  }

  char buf[bufsz], *bufptr = buf;
private:

  template <typename T>
  void operator()(T* b, T* e) {
    bool sign = 0;
    while (b != e) {
      if (++bufptr == buf + bufsz) {
        read();
      } else if (*bufptr == '-') {
        sign = 1;
      } else if (*bufptr < '0') {
        *b++ *= sign? -1: 1, sign = 0;
      } else {
        *b = *b * 10 + *bufptr - '0';
      }
    }
  }
} reader;

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

struct Point {
  int x, y, c;

  void rot90() {
    auto t = x; x = y; y = -t;
  }

  struct XCmp {
    bool operator()(const Point& a, const Point& b) const { return a.x < b.x; }
  };

  struct YCmp {
    bool operator()(const Point& a, const Point& b) const { return a.y < b.y; }
  };
};

constexpr int N = 1e5;

Point x_[N], y_[N], *x = x_, *y = y_;
int n;

int solvexy() {
  int ans = 0;
  auto ord = array{1, 2, 3};
  do {
    int px = 0, py = 0, cnt[3]{0, 0, n / 3}, bx = -2e9, by = -2e9;
    while (cnt[0] <= cnt[2]) {
      maxi(ans, cnt[0]);
      if (cnt[0] * 3 == n) {
        break;
      }
      while (x[px].c != ord[0]) {
        if ((x[px].y <= by) == (x[px].c == ord[1])) {
          --cnt[1 + (x[px].c != ord[1])];
        }
        ++px;
      }
      ++cnt[0], bx = x[px++].x;
      while (px < n && x[px].x == bx) {
        if (x[px].c == ord[0]) {
          ++cnt[0];
        } else if ((x[px].y <= by) == (x[px].c == ord[1])) {
          --cnt[1 + (x[px].c != ord[1])];
        }
        ++px;
      }
      while (py < n && (cnt[1] < cnt[0] || y[py].y <= by)) {
        if (y[py].x > bx && y[py].c != ord[0]) {
          y[py].c == ord[1]? ++cnt[1]: --cnt[2];
        }
        by = y[py++].y;
      }
    }
  } while (next_permutation(ord.begin(), ord.end()));
  return ans;
}

int solvex() {
  int ans = 0;
  auto ord = array{1, 2, 3};
  do {
    int pl = 0, pr = 0, cnt[3]{0, 0, n / 3}, bl = -2e9, br = -2e9;
    while (cnt[0] <= cnt[2]) {
      maxi(ans, cnt[0]);
      if (cnt[0] * 3 == n) {
        break;
      }
      int tcnt = cnt[0];
      while (cnt[0] == tcnt || pl < n && x[pl].x <= bl) {
        if (x[pl].c == ord[0]) {
          ++cnt[0];
        } else if (x[pl].c == ord[1]) {
          --cnt[1];
        }
        bl = x[pl++].x;
      }
      while (pr < n && (cnt[1] < cnt[0] || x[pr].x <= br)) {
        if (x[pr].c != ord[0]) {
          x[pr].c == ord[1]? ++cnt[1]: --cnt[2];
        }
        br = x[pr++].x;
      }
    }
  } while (next_permutation(ord.begin(), ord.end()));
  return ans;
}

int main() {
  reader(n);
  reader(&x_[0].x, 3 * n);
  copy_n(x_, n, y_);
  sort(x_, x_ + n, Point::XCmp{});
  sort(y_, y_ + n, Point::YCmp{});
  int ans = 0;
  for (int i = 0; i < 4; ++i) {
    maxi(ans, solvexy());
    if (i < 2) {
      maxi(ans, solvex());
    }
    for (auto& p: range{x_, n}) {
      p.rot90();
    }
    for (auto& p: range{y_, n}) {
      p.rot90();
    }
    swap(x, y);
    reverse(y, y + n);
  }
  print(ans * 3);
}