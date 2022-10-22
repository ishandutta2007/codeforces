#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100000;
ll n,A,cf,cm,m;
ll a[N+5],b[N+5],sum[N+5];
struct node
{
	ll id;
	ll cost;
}c[N+5];
ll find(ll l,ll r,ll x,ll n)
{
	ll best=a[1];
	while(l<=r)
	{
		ll mid=(l+r)/2;
		ll now=lower_bound(a+1,a+n+1,mid)-a-1;
		if(now*mid-sum[now]<=x) best=mid,l=mid+1;
		else r=mid-1;
	}
	return best;
}
bool cmp(node a,node b)
{
	return a.cost<b.cost;
}
bool cmpcmp(node a,node b)
{
	return a.id<b.id;
}
int main()
{
	scanf("%lld%lld%lld%lld%lld",&n,&A,&cf,&cm,&m);
	a[n+1]=A;
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]),c[i].cost=a[i],c[i].id=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n+1;i++) sum[i]=sum[i-1]+a[i];
	ll maxt=0;
	for(ll i=1;i<=n;i++) if(a[i]==A) maxt++;
	for(ll i=1;i<=n;i++) b[i]=A-a[i],b[i]+=b[i-1];
	ll ans=-1,nowfull,nowcost;
	for(ll full=0;full<=n;full++)
	{
		if(m-(b[n]-b[n-full])<0) continue;
		ll cost=find(0,A,m-(b[n]-b[n-full]),n-full);
		if(full==n)
		{
			nowfull=n;
			nowcost=A;
			ans=A*cm+full*cf;
		} 
		else if(ans<cost*cm+full*cf)
		{
			nowfull=full;
			nowcost=cost;
			ans=cost*cm+full*cf;
		}
	}
	printf("%lld\n",ans);
	sort(c+1,c+n+1,cmp); 
	for(ll i=n-nowfull+1;i<=n;i++) c[i].cost=A;
	for(ll i=1;i<=n-nowfull;i++) if(c[i].cost<nowcost) c[i].cost=nowcost;
	sort(c+1,c+n+1,cmpcmp);
	for(ll i=1;i<=n;i++) printf("%lld ",c[i].cost);
	printf("\n");
	return 0;
}