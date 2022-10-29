#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b){ return !a?b:gcd(b%a,a); }
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b) return x=1,y=0,a;
	ll d=exgcd(b,a%b,x,y),t=x;
	y=t-(a/b)*(x=y);
	return d;
}
inline ll mod(ll x,ll y){ return (x%=y)<0?x+y:x; }
ll solve(int n,ll m[],ll c[])
{
	for(int i=0;i<n;i++)
		if(c[i]>=m[i]) return -1;
	ll ans=c[0], LCM=m[0],x,y,g;
	for(int i=1;i<n;i++)
	{
		if(LCM<m[i])
			swap(LCM,m[i]),swap(ans,c[i]);
		g= exgcd(LCM,m[i],x,y);
		if( (c[i]-ans)%g ) return -1;
		ans += LCM*mod((c[i]-ans)/g*x,m[i]/g);
		ans %= LCM *= m[i]/g;
	}
	return ans;
}

const int maxn = 1010000;

ll n,m,N;
ll a[maxn],b[maxn],ia[maxn],ib[maxn];
vector< pair<ll,ll> >V;
ll K;

bool judge(const ll mid)
{
	ll num=mid+1;
	for(auto k:V)
	{
		ll temp=k.first,temp2=k.second;
		if(temp==-1) continue;
		
		if(temp<=mid) num--,num-=(mid-temp)/temp2;
	}
	return num>=K;
}

int main()
{
	scanf("%lld%lld%lld",&n,&m,&K); N=2*max(n,m);
	memset(ia,-1,sizeof ia);
	memset(ib,-1,sizeof ib);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		ia[a[i]]=i-1;
	}
	for(int i=1;i<=m;i++) 
	{
		scanf("%lld",&b[i]);
		ib[b[i]]=i-1;
	}
	for(int i=0;i<maxn;i++) if(ia[i]!=-1&&ib[i]!=-1)
	{
		ll m1[]={n,m},m2[]={ia[i],ib[i]};
		ll temp=solve(2,m1,m2);
		ll temp2=n*m/gcd(n,m);
		
		V.push_back(make_pair(temp,temp2));
	}
	
	ll l=K-1,r=4e18;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(judge(mid-1)) r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",r+1);
	
	return 0;
}