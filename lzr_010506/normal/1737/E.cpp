#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int pw[N], ans[N], d[N];

int qpow(int x, int times)
{
	int res = 1;
	while(times)
	{
		if(times & 1) res = 1LL * res * x % mod;
		x = 1LL * x * x % mod;
		times >>= 1;
	}
	return res;
}

int main()
{
	pw[0] = 1;
	for(int i = 1; i <= 1000000; i ++) pw[i] = 2LL * pw[i - 1] % mod;
	for(int i = 1; i <= 1000000; i ++) pw[i] = qpow(pw[i], mod - 2);
	int T;
	scanf("%d", &T);
	while(T --)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) d[i] = 0;
		int s = 0;
		for(int i = n; i >= 1; i --)
		{
			(s += d[i]) %= mod;
			int l = i / 2;
			ans[i] = pw[i - l];
			if(i == n) ans[i] = pw[i - l - 1];
			ans[i] = 1LL * ans[i] * (mod - s + 1) % mod;
			(d[l] += ans[i]) %= mod;
		}
		for(int i = 1; i <= n; i ++) printf("%d\n", ans[i]);
	}

	return 0;
}