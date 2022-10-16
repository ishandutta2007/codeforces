#include <bits/stdc++.h>

using namespace std;

struct MS {
  map<unsigned, unsigned, greater<>> body;

  void insert(int key, unsigned val) {
    auto it = body.lower_bound(key);
    if (it != body.end() && it->second <= val) {
      return;
    } else if (it != body.end() && it->first == key) {
      it->second = val;
    } else {
      it = body.emplace_hint(it, key, val);
    }
    while (it != body.begin() && (--it)->second >= val) {
      it = body.erase(it);
    }
  }

  bool query(int key, unsigned val) {
    auto it = body.lower_bound(key);
    return it != body.end() && it->second <= val;
  }
};

constexpr int S = 1 << 18, X = 2e8;

MS st[S];
unsigned v;

int query(int x, int t, int i, int L, int R) {
  if (R == L + 1) {
    return L;
  } else if (st[2 * i + 2].query(t * v + X - x, t * v + X + x)) {
    return query(x, t, 2 * i + 2, (L + R) / 2, R);
  } else {
    return query(x, t, 2 * i + 1, L, (L + R) / 2);
  }
}

void insert(int pos, int x, int t, int i, int L, int R) {
  st[i].insert(t * v + X - x, t * v + X + x);
  int M = (L + R) / 2;
  if (R == L + 1) {
    return;
  } else if (pos < M) {
    return insert(pos, x, t, 2 * i + 1, L, M);
  } else {
    return insert(pos, x, t, 2 * i + 2, M, R);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<array<int, 2>> events;
  int mxt = -1;
  for (int i = 0; i < n; ++i) {
    int x, t;
    cin >> x >> t;
    events.push_back({t, x});
    mxt = max(mxt, t);
  }
  cin >> v;
  sort(events.rbegin(), events.rend());
  int ans0 = -1, ans1 = -1;
  for (auto tx: events) {
    ans0 = query(tx[1], mxt - tx[0], 0, 0, n + 1) + 1;
    ans1 = max(ans1, ans0);
    insert(ans0, tx[1], mxt - tx[0], 0, 0, n + 1);
  }
  ans0 = query(0, mxt, 0, 0, n + 1);
  cout << ans0 << ' ' << ans1;
}