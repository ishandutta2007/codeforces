#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100000;
const ll M=1000;
const ll INF=1e16;
ll f[M+5][M+5],t[M+5][M+5];
ll x,bucket[M+5],n;
int main()
{
	scanf("%lld",&n);
	vector<ll> a;
	for(ll i=1;i<=n;i++) 
	{
		scanf("%lld",&x);
		if(x==0) continue;
		a.push_back(x);
	}
	n=a.size();
	for(ll i=0;i<n;i++)
	{
		ll num=a[i],tot=0;
		while(num>0)
		{
			bucket[tot]+=num%2;
			num/=2;
			tot++;
		}
	}
	for(ll i=0;i<=M;i++)
	{
		if(bucket[i]>=3)
		{
			printf("3\n");
			return 0;
		}
	}
	for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) f[i][j]=INF;
	for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) t[i][j]=INF;
	for(ll i=0;i<n;i++) f[i][i]=t[i][i]=0;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if((a[i]&a[j])>0) t[i][j]=t[j][i]=f[i][j]=f[j][i]=1;
		}
	}
	ll ans=INF;
	for(ll k=0;k<n;k++)
	{
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				if(i==j||i==k||j==k) continue;
				if(ans>t[i][j]+f[i][k]+f[k][j])
				{
					ans=t[i][j]+f[i][k]+f[k][j];
				} 
			}
		}
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				if(t[i][j]>t[i][k]+t[k][j]) t[i][j]=t[i][k]+t[k][j];
			}
		}
	}
	if(ans==INF) printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}