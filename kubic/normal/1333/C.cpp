#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
int n,pr[N],ps[N];ll ans,a[N],ds[N];
int id(ll x) {return lower_bound(ds+1,ds+ds[0]+1,x)-ds;}
int main()
{
	ds[++ds[0]]=0;scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]),a[i]+=a[i-1],ds[++ds[0]]=a[i];
	sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=ds[0];++i) pr[i]=-1;pr[id(0)]=0;
	for(int i=1,t;i<=n;++i)
	{
		t=id(a[i]);ps[i]=max(ps[i-1],pr[t]+2);
		ans+=i-ps[i]+1;pr[t]=i;
	}printf("%lld\n",ans);return 0;
}