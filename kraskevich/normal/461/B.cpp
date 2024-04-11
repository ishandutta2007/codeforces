#include <bits/stdc++.h>

using namespace std;

const long long MOD = (long long)1e9 + 7;
const int N = (int)2e5;

long long bin_pow(long long x, long long n) {
  long long res = 1;
  for (; n > 0; n /= 2) {
    if (n & 1)
      res = res * x % MOD;
    x = x * x % MOD;
  }
  return res;
}

long long rev(long long x) {
  return bin_pow(x, MOD - 2);
}

vector<int> g[N];
bool u[N];
int col[N];
long long f0[N];
long long f1[N];

void dfs(int v) {
  if (col[v] == 1) {
    f1[v] = 1;
    for (int to : g[v]) {
      dfs(to);
      f1[v] = f1[v] * (f0[to] + f1[to]) % MOD;
    }    
  } else {
    f0[v] = 1;
    for (int to : g[v]) {
      dfs(to);
      f0[v] = f0[v] * (f0[to] + f1[to]) % MOD;
    }
    for (int to : g[v])
      f1[v] = (f1[v] + f0[v] * rev(f0[to] + f1[to]) % MOD * f1[to]) % MOD; 
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  for (int i = 0; i < n; i++)
    cin >> col[i];
  dfs(0);
  cout << f1[0] << "\n"; 
  return 0;
}