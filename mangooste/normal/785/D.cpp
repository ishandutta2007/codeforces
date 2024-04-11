#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;

int n, ans = 0;
string s;
vector<int> fact, rfact;

inline int mult(int a, int b) {
  return 1ll * a * b % MOD;
}

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
  return a;
}

inline int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
  return a;
}

int power(int a, int b) {
  if (!b) {
    return 1;
  }
  if (b % 2) {
    return mult(a, power(a, b - 1));
  }
  return power(mult(a, a), b / 2);
}

inline int C(int n, int k) {
  return mult(mult(fact[n], rfact[k]), rfact[n - k]);
}

inline int get(int left, int right) {
  int all = C(left + right, left);
  int bad = C(left + right - 1, left - 1);
  return sub(all, bad);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> s;
  n = s.size();
  fact.assign(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    fact[i] = mult(fact[i - 1], i);
  }
  rfact.assign(n + 1, 1);
  rfact[n] = power(fact[n], MOD - 2);
  for (int i = n - 1; i; i--) {
    rfact[i] = mult(rfact[i + 1], i + 1);
  }
  int cnt_open = 0, cnt_close = 0;
  for (auto &el : s) {
    cnt_close += (el == ')');
  }
  for (int i = 0; i < n; i++) {
    cnt_close -= (s[i] == ')');
    cnt_open += (s[i] == '(');
    if (s[i] == '(') {
      ans = add(ans, get(cnt_open, cnt_close));
    }
  }
  cout << ans << '\n';
}