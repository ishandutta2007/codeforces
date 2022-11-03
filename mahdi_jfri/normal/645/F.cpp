#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const int mod = 1e9 + 7;

int cnt[maxn] , fac[maxn] , caf[maxn] , t[maxn];

vector<int> d[maxn];

void ok(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int pw(int a , int b)
{
	if(!b)
		return 1;

	int x = pw(a , b / 2);
	x = 1LL * x * x % mod;

	if(b & 1)
		x = 1LL * x * a % mod;
	return x;
}

int c(int s , int r)
{
	if(r > s)
		return 0;
	int res = 1LL * fac[s] * caf[r] % mod;
	res = 1LL * res * caf[s - r] % mod;
	return res;
}

int main()
{
	fac[0] = 1;
	for(int i = 1; i < maxn; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;

	caf[maxn - 1] = pw(fac[maxn - 1] , mod - 2);
	for(int i = maxn - 1; i >= 1; i--)
		caf[i - 1] = 1LL * caf[i] * i % mod;

	for(int i = 1; i < maxn; i++)
	{
		d[i].pb(i);
		cnt[i] += i;
		for(int j = 2 * i; j < maxn; j += i)
			cnt[j] -= cnt[i] , d[j].pb(i);
	}
			
	int n , k , q;
	cin >> n >> k >> q;

	int ans = 0;

	for(int i = 0; i < n + q; i++)
	{
		int x;
		scanf("%d", &x);
		for(auto div : d[x])
		{
			ok(ans += 1LL * c(t[div], k - 1) * cnt[div] % mod);
			t[div]++;
		}
		if(i >= n)
			printf("%d\n", ans);
	}
}