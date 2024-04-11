#include<bits/stdc++.h>
using namespace std;
const int N = 300000 + 10;
const int mod = 998244353;
int n;
int a[N];
int qpow(int a, int b)
{
  int res = 1;
  for(; b; b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod;
  return res;
}
int main()
{
  scanf("%d", &n);
  n *= 2;
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; i++) a[i] %= mod;
  int ans = 0;
  for(int i = 1; i <= n / 2; i++) ans = (ans - a[i] + mod) % mod;
  for(int i = n / 2 + 1; i <= n; i++) ans = (ans + a[i]) % mod;
  for(int i = n; i >= n / 2 + 1; i--) ans = 1ll * ans * i % mod;
  for(int i = n / 2; i >= 1; i--) ans = 1ll * ans * qpow(i, mod - 2) % mod;
  printf("%d\n", ans);
  return 0;
}