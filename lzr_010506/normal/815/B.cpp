#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200010;
const int mod = 1e9+7;

int n;
int A[N],tmp[N],fac[N];
ll jc[N], ni[N];

ll qpow(ll a,int b)
{
    ll ans = 1, base = a;
    while (b > 0)
    {
        if (b % 2 == 1) ans = (base * ans) % mod;
        base = (base * base) % mod;
        b /= 2;
    }
    return ans;
}

int C(int n, int b)
{
    if(n == b || b == 0) return 1;
   	return ((jc[n] * ni[b] % mod) * ni[n - b]) % mod;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%d",&A[i]);
	jc[0] = 1;
	ni[0] = 1;
	for(int i = 1; i < N; i ++)
		jc[i] = jc[i - 1] * i % mod;
	for(int i = 1; i < N; i ++)
		ni[i] = qpow(jc[i], mod - 2);
	int now = 0;
	while(n % 4)
    {
		if(n == 1)
		{
			printf("%d\n",A[1]);
			exit(0);
		}
		for(int i = 1; i < n; i ++)
		{
			if(!now) tmp[i] = (A[i] + A[i + 1]) % mod;
			else tmp[i] = (A[i] - A[i + 1] + mod) % mod;
			now ^= 1;
		}
		n --;
		for(int i = 1; i <= n; i ++)
            A[i] = tmp[i];
	}
	ll ans = 0;
	for(int i = 0; i < n / 2; i ++)
        ans = (1LL * (1LL * A[i * 2 + 1] + (now == 0 ? -A[i * 2 + 2]: A[i *2 + 2]) + mod) % mod * C(n / 2 - 1, i) % mod + ans) % mod;
	cout << ans;
	return 0;
}