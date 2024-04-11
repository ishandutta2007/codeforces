#include <iostream>

using namespace std;

constexpr int N = 2e5, max_size = 1 << 19;

struct Node {
  int pnd, snd, l, r;
  int64_t s;
  int8_t covered;
};

Node combine(const Node& L, const Node& R) {
  if (!L.s || !R.s) {
    return L.s? L: R;
  }
  int8_t overlap = -(L.r <= R.l);
  return {
    L.pnd + (overlap & L.covered & R.pnd),
    R.snd + (overlap & R.covered & L.snd),
    L.l,
    R.r,
    L.s + R.s + (overlap & L.snd) * (int64_t)R.pnd,
    overlap & L.covered & R.covered,
  };
}

Node t[max_size];

struct STOperation {
  int query, l, r, val;

  Node call(int i = 0, int L = 0, int R = N) {
    Node dummy{};
    Node& maybe = query? dummy: t[i];
    if (R <= l || L >= r) {
      return maybe;
    } else if (l <= L && R <= r) {
      maybe = {1, 1, val, val, 1, -1};
      return t[i];
    }
    return maybe = combine(call(2 * i + 1, L, (L + R) / 2), call(2 * i + 2, (L + R) / 2, R));
  }
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, q, val;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> val;
    STOperation{0, i, i + 1, val}.call();
  }
  while (q--) {
    int qt, a, b;
    cin >> qt >> a >> b;
    if (qt == 1) {
      STOperation{0, a - 1, a, b}.call();
    } else {
      cout << STOperation{1, a - 1, b}.call().s << '\n';
    }
  }
  return 0;
}