#include <cstdio>
#include <algorithm>
 
const int mod = 998244353;
int G = 3, Gi = 332748118;
int id[2097163], A[2097163];
int st[17][2097153];

int qpow(int x, int p)
{
    int ans = 1;
    while(p)
    {
        if(p & 1) ans = 1ll * ans * x % mod;
        x = 1ll * x * x % mod; p >>= 1;
    }
    return ans;
}

void NTT(int lim, int *a, int type)
{
    for(int i = 0; i < lim; i++)
        if(id[i] > i) std::swap(a[id[i]], a[i]);
    for(int len = 2; len <= lim; len <<= 1)
    {
        int Wn = qpow(type == 1 ? G : Gi, (mod - 1) / len);
        for(int j = 0; j < lim; j += len)
        {
            int W = 1;
            for(int i = 0; i < (len >> 1); i++, W = 1ll * W * Wn % mod)
            {
                int t1 = a[j + i], t2 = 1ll * W * a[j + (len >> 1) + i] % mod;
                a[j + i] = (t1 + t2) % mod;
                a[j + (len >> 1) + i] = (t1 - t2 + mod) % mod;
            }
        }
    }
    if(type == -1)
    {
        for(int i = 0; i < lim; i++) a[i] = 1ll * qpow(lim, mod - 2) * a[i] % mod;
    }
}

int Ans[2097163];
int main()
{
	int n, k; scanf("%d%d", &n, &k);
	n >>= 1;
	for(int i = 1; i <= k; i++)
	{
		int x; scanf("%d", &x);
		st[0][x] = 1;
	}
	for(int I = 1; I <= 16; I++)
	{
		int lim = 1, R = 0;
		int N = 9 * (1 << I) + 1;
	    while(lim < N) lim <<= 1, R++;
	    for(int i = 0; i < lim; i++)
	    {
	        id[i] = id[i >> 1] >> 1;
	        if(i & 1) id[i] |= (1 << R - 1);
	    }
	    for(int j = 0; j < lim; j++) A[j] = st[I - 1][j];
	    NTT(lim, A, 1);
	    for(int j = 0; j < lim; j++) st[I][j] = 1ll * A[j] * A[j] % mod;
	    NTT(lim, st[I], -1);
	}
	Ans[0] = 1;
	int sum = 0;
	for(int I = 0; I <= 16; I++)
	{
		if((n >> I) & 1)
		{
			sum += (1 << I) * 9;
			int lim = 1, R = 0;
			while(lim < sum + 1) lim <<= 1, R++;
			for(int i = 0; i < lim; i++)
		    {
		        id[i] = id[i >> 1] >> 1;
		        if(i & 1) id[i] |= (1 << R - 1);
		    }
		    for(int j = 0; j < lim; j++) A[j] = st[I][j];
		    NTT(lim, A, 1); NTT(lim, Ans, 1);
		    for(int j = 0; j < lim; j++) Ans[j] = 1ll * A[j] * Ans[j] % mod;
		    NTT(lim, Ans, -1);
		}
	}
	int ans = 0;
	for(int i = 0; i <= 2000000; i++) ans = (ans + 1ll * Ans[i] * Ans[i] % mod) % mod;
	printf("%d\n", ans);
}