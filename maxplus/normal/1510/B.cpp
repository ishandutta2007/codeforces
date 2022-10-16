#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

constexpr int N = 1 << 10;

int vis[N];
bool hv[N];
vector<int> prec[N];
int prv[N], nxt[N];
int pc[N];
int a[N];

void cnct(int u, int v) {
  prv[v] = u;
  nxt[u] = v;
}

bool try_connect(int v, int maxp) {
  if (vis[v] >= maxp) {
    return 0;
  }
  if (maxp >= pc[v] + 1) {
    prv[v] = -1;
    return 1;
  }
  vis[v] = maxp;
  for (auto u: prec[v]) if (!nxt[u] && pc[v] - pc[u] <= maxp) {
    cnct(u, v);
    return 1;
  }
  for (auto u: prec[v]) if (auto t = nxt[u]) if (prv[t] = -1, cnct(u, v), try_connect(t, maxp - pc[v] + pc[t])) {
    return 1;
  } else {
    cnct(u, t);
    prv[v] = -1;
  }
  return 0;
}

int main() {
  int d, n; cin >> d >> n;
  for (int i = 0; i < 1 << d; ++i) {
    pc[i] = __builtin_popcount(i);
  }
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    int x = 0;
    while (s.size()) {
      x = x * 2 + s.back() - '0'; s.pop_back();
    }
    a[i] = x;
  }
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    hv[x] = 1;
    for (int y = x; y && (y = (y - 1) & x, 1); ) if (hv[y]) {
      prec[x].push_back(y);
    }
    memset(vis, -1, sizeof vis);
    for (int k = 0; k <= pc[x] + 1; ++k) if (try_connect(x, k)) {
      break;
    }
  }
  vector<char> ans;
  for (int i = 0; i < 1 << d; ++i) if (hv[i] && !nxt[i]) {
    vector<char> cur;
    for (int j = i; j > 0; ) {
      auto p = prv[j];
      if (p == -1) {
        p = 0;
      }
      while (j != p) {
        auto t = __builtin_ctz(j & ~p);
        cur.push_back(t + '0');
        j ^= 1 << t;
      }
    }
    ans.insert(ans.end(), cur.rbegin(), cur.rend());
    ans.push_back('R');
  }
  ans.pop_back();
  cout << ans.size() << '\n';
  for (auto c: ans) {
    cout << c << ' ';
  }
}