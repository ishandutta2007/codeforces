#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod = 1e9 + 7, maxn = 500000;
int jc[555555], injc[555555], a[555555], n, ans;
int binpow(int a, int t)
{
    int res = 1, p = a;
    for (int i = t; i; i >>= 1)
    {
        if (i & 1) res = 1ll * res * p % mod;
        p = 1ll * p * p % mod;
    }
    return res;
}
int C(int n, int k)
{
    if (n < k || n < 0 || k < 0) return 0;
    return 1ll * jc[n] * injc[k] % mod * injc[n - k] % mod;
}
void Init()
{
    jc[0] = injc[0] = 1;
    for (int i = 1; i <= maxn; i++) jc[i] = 1ll * jc[i - 1] * i % mod;
    injc[maxn] = binpow(jc[maxn], mod - 2);
    for (int i = maxn - 1; i >= 0; i--) injc[i] = 1ll * injc[i + 1] * (i + 1) % mod;
}
int main()
{
    scanf("%d", &n);
    Init();
    for (int i = 0; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++)
    {
        ans = (ans + C(i + a[i], i + 1)) % mod;
    }
    printf("%d\n", ans);
	return Accepted;
}