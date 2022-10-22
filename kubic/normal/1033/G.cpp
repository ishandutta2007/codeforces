#include <bits/stdc++.h>
using namespace std;
#define N 105
#define M 200005
#define ll long long
int n,m,b[N];ll ans[2],a[N];
int slv(int x)
{
	int res=0,cnt=0,mx1=0,mx2=0;
	for(int i=1;i<=n;++i)
	{
		b[i]=a[i]%x;if(b[i]>=(x+1)/2) ++cnt;
		if(b[i]>mx1) mx2=mx1,mx1=b[i];else if(b[i]>mx2) mx2=b[i];
	}res=mx2/2;for(int i=1;i<=n;++i) res=max(res,min(b[i],x-b[i]-1));
	if(!(cnt&1)) res=x/2;if(res<x/2) return res;res=x-mx1/2-1;
	for(int i=1;i<=n;++i) res=min(res,max(b[i],x-b[i]-1));return res;
	
}
int main()
{
	scanf("%d %d",&n,&m);for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=2,l,r,t,t1;i<=m*2;++i)
	{
		l=max(i-m,1);r=min(i-1,m);t=slv(i);t=max(t,l-1);t=min(t,r);
		t1=min(t-l+1,r-t);ans[0]+=t1;ans[1]+=t-l-t1+1;
	}printf("%lld %lld %lld %lld\n",ans[0],ans[0],1ll*m*m-ans[0]*2-ans[1],ans[1]);
	return 0;
}