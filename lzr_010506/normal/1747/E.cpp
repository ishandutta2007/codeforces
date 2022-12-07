#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 10;
int jc[N], ny[N], pw[N];
int C(int n, int m)
{
	return 1LL * jc[n] * ny[m] % mod * ny[n - m] % mod;
}
int main()
{
	jc[0] = ny[0] = 1;
	jc[1] = ny[1] = 1;
	pw[0] = 1; pw[1] = 2;
	for(int i = 2; i < N; i ++) 
	{
		jc[i] = 1LL * jc[i - 1] * i % mod;
		pw[i] = pw[i - 1] * 2LL % mod;
		ny[i] = 1LL * (mod - mod / i) * ny[mod % i] % mod;
	}
	for(int i = 1; i < N; i ++) ny[i] = 1LL * ny[i] * ny[i - 1] % mod;
	int T;
	scanf("%d", &T);
	while(T --)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int ans = 0;
		int mm = min(n, m);
		for(int i = 0; i <= mm; i ++)
		{
			int s = n + m - i - 1;
			int pp = 1LL * C(n, i) * C(m, i) % mod;
			ans = ans + 1LL * pp * pw[s] % mod * (i + 2) % mod; ans %= mod;
			if(s) {ans = ans + 1LL * pp * s % mod * pw[s - 1] % mod; ans %= mod;}
		}
		printf("%d\n", ans);
	}
	return 0;
}