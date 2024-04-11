#include <bits/stdc++.h>
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define int long long
using namespace std;
int n, m, k;
int a[1000002],fa[1000002],b[1000002],dp[1000002],p[1000002];
const int mod=1e9+7;
signed main()
{
	cin>>n;
	up(i,1,n)scanf("%lld",&a[i]);
	up(i,2,n)scanf("%lld",&fa[i]);
	down(i,n,2)a[fa[i]]+=a[i];
	up(i,1,n)++p[min(n+1,a[1]/__gcd(a[1],a[i]))];
	up(i,1,n)for(int j=i;j<=n;j+=i)b[j]+=p[i];
	int sum=0;
	up(i,1,n)
	{
		if(b[i]==i&&a[1]%i==0)
		{
			if(i==1)dp[i]++;
			for(int j=i+i;j<=n;j+=i)dp[j]+=dp[i],dp[j]%=mod;
			sum+=dp[i];
			sum%=mod;
		}
	}
	cout<<sum;
}