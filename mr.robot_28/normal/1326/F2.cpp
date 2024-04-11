#include<bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ll;
const int N = 19;
 
int g[N];
ll dp[1 << N][N+1];
ll ok[1 << N];
 
ll slen[N+1][1 << N];
 
ll cur[N+1][1 << N];
ll val[1 << N];
 
ll ans[1 << N];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == '1') {
        g[i] |= (1 << j);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    dp[1 << i][i] = 1;
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      int cands = g[i] & (~mask);
      for (int j = 0; j < n; j++) {
        if ((cands >> j) & 1) {
          dp[mask | (1 << j)][j] += dp[mask][i];
        }
      }
      ok[mask] += dp[mask][i];
    }
  }
  for (int len = 1; len <= n; len++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      if (__builtin_popcount(mask) == len) {
        slen[len][mask] += ok[mask];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        if ((mask >> i) & 1) {
          slen[len][mask] += slen[len][mask ^ (1 << i)];
        }
      }
    }
  }
  map <vector <int>, vector <int> > ok;
  for (int mask = 0; mask < (1 << (n - 1)); mask++) {
    int x = 0;
    vector <int> t;
    while (x < n) {
      int len = 1;
      while ((mask >> x) & 1) {
        x++;
        len++;
      }
      t.push_back(len);
      x++;
    }
    sort(t.begin(), t.end());
    ok[t].push_back(mask);
  }
  vector <int> a;
  for (int mask = 0; mask < (1 << n); mask++)
    val[mask] = 1;
  function<void(int,int)> f = [&] (int s, int last) {
    if (s == n) {
      ll ret = 0;
      int x = (1 << n) - 1;
      for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) % 2 == 0)
          ret += val[x ^ mask];
        else
          ret -= val[x ^ mask];
      }
      for (auto c : ok[a]) {
        ans[c] += ret;
      }
      return;
    }
    if (s + last > n) {
      return;
    }
    for (int mask = 0; mask < (1 << n); mask++) {
      cur[s][mask] = val[mask];
    }
    for (int i = last; s + i <= n; i++) {
      if (s + i != n && s + i + i > n) continue;
      a.push_back(i);
      for (int mask = 0; mask < (1 << n); mask++) {
        val[mask] *= slen[i][mask];
      }
      f(s + i, i);
      for (int mask = 0; mask < (1 << n); mask++) {
        val[mask] = cur[s][mask];
      }
      a.pop_back();
    }
  };
  f(0, 1);
  for (int i = 0; i < (n - 1); i++) {
    for (int mask = 0; mask < (1 << (n - 1)); mask++) {
      if (!((mask >> i) & 1)) {
        ans[mask] -= ans[mask + (1 << i)];
      }
    }
  }
  for (int mask = 0; mask < (1 << (n - 1)); mask++) {
    cout << ans[mask] << ' ';
  }
  cout << endl;
}