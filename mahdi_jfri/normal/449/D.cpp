#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
const int maxn = 1e6 + 20;
const int maxb = 21;
const ll mod = 1e9 + 7;

ll a[maxn] , dp[maxn] , t[maxn] , x[maxn];

int main()
{
	t[0] = 1;
	for(int i = 1; i < maxn; i++)
		t[i] = (t[i - 1] * 2) % mod;
	for(int i = 0; i < maxn; i++)
		x[i] = x[i / 2] + (i & 1);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		dp[a[i]]++;
	}
	for(int j = 0; j <= maxb; j++)
		for(int i = maxn - 1; i >= 0; i--)
			if(bit(i , j))
				dp[i ^ (1 << j)] += dp[i];
	ll ans = t[n];
	for(int i = 1; i < maxn; i++)
	{
		if(x[i] % 2)
			ans -= t[dp[i]];
		else
			ans += t[dp[i]];
		ans = ((ans % mod) + mod) % mod;
	}
	cout << ans << endl;
}