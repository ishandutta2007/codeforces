#include <bits/stdc++.h>
using namespace std;

const int MGC[3] = {1004535809, 998244353, 104857601};
const int MOD = 1000000007;
int P;
const int G = 3;

int quick_mod(int x, int k, int MOD) 
{
    int ans = 1;
    while (k) 
    {
        if (k & 1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        k >>= 1;
    }
    return ans;
}

void change(int *y, int len) 
{
    int i, j, k;
    for(i = 1, j = len / 2; i < len - 1; i ++) 
    {
        if(i < j) swap(y[i], y[j]);
        k = len / 2;
        while(j >= k) 
        {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}

void ntt(int *y, int len, int on) 
{
    change(y, len);
    int id = 0;
    for(int h = 2; h <= len; h <<= 1) 
    {
        id++;
        int wn = quick_mod(G, (P - 1) / (1<<id), P);
        for(int j = 0; j < len; j += h) 
        {
            int w = 1;
            for(int k = j; k < j + h / 2; k ++) 
            {
                int u = y[k] % P;
                int t = 1LL * w * y[k + h / 2] % P;
                y[k] = (u + t) % P;
                y[k + h / 2] = ((u - t) % P + P) % P;
                w = 1LL * w * wn % P;
            }
        }
    }
    if(on == -1) 
    {
        for (int i = 1; i < len / 2; i ++)
            swap(y[i], y[len - i]);
        int inv = quick_mod(len, P - 2, P);
        for(int i = 0; i < len; i++)
            y[i] = 1LL * y[i] * inv % P;
    }
}

const int N = 30005;

int n, k;
int dp[20][N], x1[N * 4], x2[N * 4], tmp[N][3];
int f[N], rf[N], r[3][3], pow2[N];

int CRT(int *a) 
{
	int sb[3];
	for(int i = 0; i < 3; i ++) 
	{
		sb[i] = a[i];
		for(int j = 0; j < i; j ++) 
		{
			int t = (sb[i] - sb[j]) % MGC[i];
			if(t < 0) t += MGC[i];
			sb[i] = 1LL * t * r[j][i] % MGC[i];
		}
	}
	int mul = 1, ans = sb[0] % MOD;
	for(int i = 1; i < 3; i ++) 
	{
		mul = 1LL * mul * MGC[i - 1] % MOD;
		ans = (ans + 1LL * sb[i] * mul % MOD) % MOD;
	}
	return ans;
}

int t1[N * 4], t2[N * 4];

void gao(int *dp, int *a, int *b, int n) 
{
    int len = 1;
    while (len < (k + 1) * 2) len *= 2;
    int p2 = 1;
    for (int i = 0; i < len; i++) 
    {
        t1[i] = (i <= k ? 1LL * a[i] * rf[i] % MOD * p2 % MOD : 0LL);
        p2 = 1LL * p2 * pow2[n] % MOD;
    }
    for (int i = 0; i < len; i++) t2[i] = (i <= k ? 1LL * b[i] * rf[i] % MOD : 0LL);
    for (int ti = 0; ti < 3; ti++) 
    {
        P = MGC[ti];
        for (int i = 0; i < len; i++)
            x1[i] = t1[i], x2[i] = t2[i];
        ntt(x1, len, 1); ntt(x2, len, 1);
        for (int i = 0; i < len; i++)
            x1[i] = 1LL * x1[i] * x2[i] % P;
        ntt(x1, len, -1);
        for (int i = 0; i <= k; i++)
            tmp[i][ti] = x1[i];
    }
    for (int i = 0; i <= k; i++)
        dp[i] = 1LL * CRT(tmp[i]) * f[i] % MOD;
}

int dp2[2][N];

int C(int n, int m) 
{
    if (n < 0 || m < 0 || m > n) return 0;
    return 1LL * f[n] * rf[m] % MOD * rf[n - m] % MOD;
}

void init() 
{
    f[0] = pow2[0] = 1;
    for (int i = 1; i <= k; i++) 
    {
        pow2[i] = pow2[i - 1] * 2 % MOD;
        f[i] = 1LL * f[i - 1] * i % MOD;
    }
    rf[k] = quick_mod(f[k], MOD - 2, MOD);
    for (int i = k - 1; i >= 0; i--) rf[i] = 1LL * rf[i + 1] * (i + 1) % MOD;
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            r[i][j] = quick_mod(MGC[i], MGC[j] - 2, MGC[j]);
}

int solve() 
{
    if (n > k) return 0;
    init();
    for (int i = 1; i <= k; i++) dp[0][i] = 1;
    for (int i = 1; (1<<i) <= n; i++)
        gao(dp[i], dp[i - 1], dp[i - 1], (1<<(i - 1)));
    int now = 0, pre = 1, flag = 0;
    for (int i = 0; (1<<i) <= n; i++) 
    {
        if (!((n>>i)&1)) continue;
        if (!flag) 
        {
            flag = 1;
            for (int j = 0; j <= k; j++)
                dp2[now][j] = dp[i][j];
        } 
        else 
        {
            swap(now, pre);
            gao(dp2[now], dp2[pre], dp[i], (1<<i));
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) ans = (ans + 1LL * dp2[now][i] * C(k, i) % MOD) % MOD;
    return ans;
}

int main() 
{
    scanf("%d%d", &n, &k);
    printf("%d\n", solve());
    return 0;
}