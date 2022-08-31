//#ifdef DEBUG
//#define _GLIBCXX_DEBUG
//#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

constexpr int N = 500'228;

int fn[N];

void md(int x, int y) {
  while (x < N) {
    fn[x] = max(fn[x], y);
    x =(x | (x - 1)) + 1;
  }
}

int get(int x) {
  int mx = 0;
  while (x > 0) {
    mx = max(mx, fn[x]);
    x = (x & (x - 1));
  }
  return mx;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> prv(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() > 0 && a[st.back()] <= a[i]) {
      st.pop_back();
    }
    if (!st.empty()) {
      prv[i] = st.back();
    }
    st.push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    fn[i] = 0;
  }
  vector<vector<int>> qr(n);
  for (int i = 0; i < n; i++) {
    if (prv[i] != -1) {
      qr[prv[i]].emplace_back(i);
    }
  }
  vector<int> f(n, 1);
  for (int i = 0; i < n; i++) {
    f[i] = max(get(a[i]) + 1, f[i]);
    for (auto j : qr[i]) {
      f[j] = max(get(a[j]) + 2, f[j]);
    }
    md(a[i], f[i]);
  }
  int mx = 0;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans = max(ans, f[i] + (mx > a[i]));
    mx = max(mx, a[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  for (; t >= 1; t--) {
    solve();
  }
  return 0;
}