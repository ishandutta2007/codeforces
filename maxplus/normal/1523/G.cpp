#include <algorithm>
#include <utility>
#include <random>
#include <list>
#include <stack>
#include <queue>
#include <tuple>
#include <cstdlib>
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

constexpr int N = 5e4, M = 1e5, LOGN = 16;

int& mini(int& lhs, int rhs) {
  return lhs = min(lhs, rhs);
}

struct CT;

class CTVertex {
public:
  using CTPtr = CTVertex*;

  CTVertex() = delete;

  CTVertex(int x, int y, int t): x{x}, y{y}, t{t}, mint{}, l{}, r{} {};

  static void add(CTPtr& t, CTPtr el) {
    if (!t) {
      t = el;
    } else if (t->y > el->y) {
      if (split(t, el->x, el->l, el->r, el->t)) {
        t = el;
      }
    } else if (t->x == el->x) {
      mini(t->t, el->t);
    } else {
      add(t->x > el->x? t->l: t->r, el);
    }
    t->update();
  }

  static int mintlq(CTPtr a, int r) {
    if (!a) {
      return M;
    }
    if (a->x > r) {
      return mintlq(a->l, r);
    } else {
      return min({get_mint(a->l), a->t, mintlq(a->r, r)});
    }
  }

private:
  int x, y, t, mint;
  CTPtr l, r;

  static int get_mint(CTVertex *v) {
    return v? v->mint: M;
  }

  void update() {
    mint = min({get_mint(l), t, get_mint(r)});
  }

  static bool split(CTPtr t, int x, CTPtr& l, CTPtr& r, int tval/* = M*/) {
    bool uniq = 0;
    if (!t) {
      l = r = t;
      return 1;
    } else if (t->x > x) {
      (uniq = split(t->l, x, l, t->l, tval)) && (r = t);
    } else if (t->x == x) {
      mini(t->t, tval);
    } else {
      (uniq = split(t->r, x, t->r, r, tval)) && (l = t);
    }
    t->update();
    return uniq;
  }
  friend CT;
};

struct CT {
  auto create(int r, int t) {
    int y = (storage.size()? storage.top().y: rand()) * (RAND_MAX + 1u) + rand();
    storage.emplace(r, y, t);
    return &storage.top();
  }

  operator auto&() { return root; }

  stack<CTVertex, list<CTVertex>> storage;
  CTVertex* root;
};

using interval = pair<int, int>;
interval rent[M + 1];
vector<int> by_length[N + 1];
int ans[N + 1];

CT st[4 * N];

enum STTag {Add, Query};

template<STTag tag>
struct STOperation {
  int l, r, t;

  int call(int i = 0, int L = 0, int R = N) {
    if (R <= l || r <= L) {
      return M;
    }
    if constexpr (tag == Add) {
      CTVertex::add(st[i], st[i].create(rent[t].second, t));
      if (R == L + 1) {
        return M;
      }
    } else {
      if (l <= L) {
        return CTVertex::mintlq(st[i], r);
      }
    }
    return min(call(2 * i + 1, L, (L + R) / 2), call(2 * i + 2, (L + R) / 2, R));
  }
};

void add(int t) {
  STOperation<Add>{rent[t].first, rent[t].first + 1, t}.call();
}

int query(int l, int r) {
  return STOperation<Query>{l, r, -1}.call();
}

int main()
{
  int n, m;
  reader(n, m);
  reader(&rent[0].first, 2 * m);
  for (int i = 0; i < m; ++i) {
    --rent[i].first;
    by_length[rent[i].second - rent[i].first].push_back(i);
  }
  queue<interval> for_rent;
  for (int epoch = n; epoch; --epoch) {
    for (int i: by_length[epoch]) {
      add(i);
    }
    for_rent.emplace(0, n);
    while (!for_rent.empty()) {
      auto [l, r] = for_rent.front();
      for_rent.pop();
      int t = query(l, r);
      if (t != M) {
        ans[epoch] += rent[t].second - rent[t].first;
        for_rent.emplace(l, rent[t].first);
        for_rent.emplace(rent[t].second, r);
      }
    }
  }
  for (int rented = 1; rented <= n; ++rented) {
    printf("%d\n", ans[rented]);
  }
  return 0;
}