#include <functional>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int N = 1e5 + 1;

struct DSU {
  auto size(int v) {return w[getp(v)];}
  auto operator()(int v) {return getp(v);}
  auto operator()(int v, int u) {return uni(v, u);}

private:
  int p[N], w[N];

  int getp(int v) {
    return p[v] == 0? v: p[v] = getp(p[v]);
  }

  void uni(int u, int v) {
    if (w[v = getp(v)] > w[u = getp(u)]) {
      v ^= u, u ^= v, v ^= u;
    }
    p[v] = u;
    w[u] += w[v] + 1;
  }
} dsu1, dsu2;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m1, m2, a, b;
  cin >> n >> m1 >> m2;
  for (int i = 0; i < m1; ++i) {
    cin >> a >> b;
    dsu1(a, b);
  }
  for (int i = 0; i < m2; ++i) {
    cin >> a >> b;
    dsu2(a, b);
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
  for (int i = 1; i <= n; ++i) {
    s.emplace(dsu1.size(i) + dsu2.size(i), i);
  }
  int ans = n - max(m1, m2) - 1;
  cout << ans << '\n';
  while (ans--) {
    while (1) {
      tie(b, a) = s.top();
      s.pop();
      if (b != dsu1.size(a) + dsu2.size(a)) {
        s.emplace(dsu1.size(a) + dsu2.size(a), a);
      } else {
        break;
      }
    }
    b = a % n + 1;
    while (dsu1(a) == dsu1(b) || dsu2(a) == dsu2(b)) {
      b = b % n + 1;
    }
    dsu1(a, b);
    dsu2(a, b);
    cout << a << ' ' << b << '\n';
  }
  return 0;
}