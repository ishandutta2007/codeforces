#include<bits/stdc++.h>
using namespace std;
#define re register
int n,m,k,p;
int hp[100100];
long long h[100100],a[100100],h1[100100];
inline long long ti(re int a1){return h1[a1]/a[a1];}
inline bool cmp(re int a1,re int b1){return ti(a1)>ti(b1);}
bool check(re long long x)
{
	re int res=m*k;
	for(re int i=1;i<=n;i++)
	{
		h1[i]=x;hp[i]=i;
	}
	make_heap(hp+1,hp+n+1,cmp);
	for(re int i=1;i<=m;i++)
	{
		for(re int j=1;j<=k;j++)
		{
			re int x=hp[1];
			if(ti(x)<i)return 0;
			if(ti(x)>=m)break;
			res--;
			pop_heap(hp+1,hp+n+1,cmp);
			h1[x]+=p;
			push_heap(hp+1,hp+n+1,cmp);
		}
	}
	for(re int i=1;i<=n;i++)
	{
		if(h1[i]-m*a[i]<h[i])
		{
			res-=(h[i]-h1[i]+m*a[i]+p-1)/p;
			if(res<0)return 0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	re long long l=0,r=0;
	for(re int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&h[i],&a[i]);
		if(h[i]+a[i]*m>r)r=h[i]+a[i]*m;
	}
	for(re long long mid=(l+r)/2;l<r;mid=(l+r)/2)
	{
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
}