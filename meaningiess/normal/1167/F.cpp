#include<bits/stdc++.h>
#define ll long long
#define N 500010
#define mod 1000000007
using namespace std;
struct piar
{
	int a,b;
	bool operator<(const piar&x) const{return a<x.a;}
}e[N];
ll ans=0;
ll c[2][N];int a[N];
void add(int t,int x,int y){for (;x<N;x+=(x&(-x))) {c[t][x]+=y;if (c[t][x]>=mod) c[t][x]-=mod;}}
ll qry(int t,int x)
{
	ll res=0;
	for (;x;x-=(x&(-x))) {res+=c[t][x];if (res>=mod) res-=mod;}
	return res;
}
int main()
{
	int n,i;scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]),e[i]={a[i],i};
	sort(e+1,e+n+1);
	for (i=1;i<=n;i++)
	{
		int w=e[i].b,h=n-w+1;add(0,h,h);add(1,h,w);
		ll k1=qry(0,h),k2=qry(1,n)-qry(1,h-1)+mod;k2%=mod;
		ans+=((k1*w+k2*h-1ll*w*h+mod)%mod)*e[i].a%mod;ans%=mod;
	}
	cout<<ans;
}