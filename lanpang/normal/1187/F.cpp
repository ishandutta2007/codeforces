#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n;
LL a[maxn] , b[maxn] , p[maxn] , ni[maxn] , s , ans;

LL qp(LL x , LL y)
{
	LL ret = 1 , gg = x;
	while (y)
	{
		if (y%2) ret = ret*gg%mod;
		gg = gg*gg%mod;
		y /= 2;
	}
	return ret;
}

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		scanf("%lld",&a[i]);
	for (i = 1 ; i <= n ; i++)
		scanf("%lld",&b[i]);
	for (i = 1 ; i <= n ; i++)
		ni[i] = qp(b[i]-a[i]+1,mod-2);
	for (i = 1 ; i <= n ; i++)
	{
		LL sg = max(0ll,min(b[i-1],b[i])-max(a[i-1],a[i])+1);
		p[i] = (mod+1-sg*ni[i-1]%mod*ni[i]%mod)%mod;
		ans = (ans+p[i])%mod;
	}
	s = ans;
	for (i = 1 ; i < n ; i++)
	{
		LL sg = max(0ll,min(b[i-1],min(b[i],b[i+1]))-max(a[i-1],max(a[i],a[i+1]))+1);
		LL p0 = sg*ni[i-1]%mod*ni[i]%mod*ni[i+1]%mod;
		LL pp = (p[i]+p[i+1]+p0+mod-1)%mod;
		ans = (ans+pp*2)%mod;
	}
	for (i = 1 ; i <= n ; i++)
	{
		LL pp = (s+mod-p[i-1]+mod-p[i]+mod-p[i+1])%mod*p[i]%mod;
		ans = (ans+pp)%mod;
	}
	cout << ans << "\n";
	return 0;
}