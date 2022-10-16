#include <cstring>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <stack>
#include <vector>

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
    while (b != e) {
      if (++bufptr == buf + bufsz) {
        read();
      } else if (*bufptr < '0') {
        ++b;
      } else {
        *b = *b * 10 + *bufptr - '0';
      }
    }
  }
} reader;

using namespace std;

constexpr int N = 2e5;

uint64_t g[N];

uint64_t gcd(uint64_t a, uint64_t b) {
  int c = __builtin_ctzll(a | b);
  a >>= __builtin_ctzll(a);
  b >>= __builtin_ctzll(b);
  if (a < b) {
    swap(a, b);
  }
  while (b) {
    do {
      a -= b;
      a >>= __builtin_ctzll(a);
    } while (a >= b);
    swap(a, b);
  }
  return a << c;
}

struct MinUnideque {
  using T = uint64_t;
  constexpr static T default_value = {};
  using C = stack<pair<T, T>, vector<pair<T, T>>>;

  static T op(T a, T b) {
    return gcd(a, b);
  }

  T get() const {
    return op(get(h), get(t));
  }

  void push_front(T x) { push(h, x); }
  void push_back(T x) { push(t, x); }
  void pop_back() { pop(t, h); }
  void pop_front() { pop(h, t); }

  void clear() {
    while (h.size()) {
      h.pop();
    }
    while (t.size()) {
      t.pop();
    }
  }

private:
  C h, t;

  static T get(const C& a) {
    return a.empty()? default_value: a.top().second;
  }

  static void push(C& a, T x) { a.emplace(x, op(x, get(a))); }
  static void pop(C& a, C& b) {
    if (!a.empty()) {
      return a.pop();
    }
    while (b.size() > 1) {
      push(a, b.top().first);
      b.pop();
    }
    b.pop();
  }
} gcdq;

int main() {
  int t, n;
  reader(t);
  while (t--) {
    reader(n);
    reader(&*g, n);
    for (int i = 1; i < n; ++i) {
      g[i - 1] = abs((int64_t)(g[i - 1] - g[i]));
    }
    if (!--n) {
      puts("1");
      continue;
    }
    int ans = 0, r = -1;
    for (int i = 0; i + ans < n; ++i) {
      do {
        gcdq.push_back(g[++r]);
      } while (gcdq.get() != 1 && r < n);
      ans = max(ans, r - i);
      gcdq.pop_front();
    }
    gcdq.clear();
    printf("%d\n", ans + 1);
  }
  return 0;
}