#include<bits/stdc++.h>
#define re register
int m,p[400100],p1[400100];
long long n,k,a[400100],b[400100];
long long che1(re long long x)
{
	re long long ans=0;
	for(re int i=1;i<=m;i++)
	{
		if(x>a[i])b[i]=1;
		else b[i]=a[i]/x;
		ans+=b[i]-1;
	}
	return ans;
}
inline bool cmp(re int i,re int j){return b[i]==1?b[j]!=1:(b[j]!=1&&((a[i]+b[i]-2)/(b[i]-1)>(a[j]+b[j]-2)/(b[j]-1)));}
inline bool cmp1(re int i,re int j){return ((a[i]+b[i]-1)/b[i]>(a[j]+b[j]-1)/b[j]);}
int main()
{
	re int t;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%lld%d%lld",&n,&m,&k);
		for(re int i=1;i<=m;i++)scanf("%lld",&a[i]);a[++m]=n;
		re long long l=1,r=n,mid;
		for(re int i=m;i;i--)a[i]-=a[i-1];
		for(mid=(l+r+1)/2;l<r;mid=(l+r+1)/2)
		{
			if(che1(mid)<k)r=mid-1;
			else l=mid;
		}
		re long long vc=che1(l)-k,mi=1ll<<60,mx=0,ans=1ll<<60;
		for(re int i=1;i<=m;i++)
		if(a[i]/b[i]==l){
			re long long yy=a[i]/(l+1);
			if(vc<=b[i]-yy-1){b[i]-=vc;vc=0;break;}
			else vc-=b[i]-yy-1,b[i]=yy+1;
		}
		for(re int i=1;i<=m;i++)p[i]=i;
		std::make_heap(p+1,p+m+1,cmp);
		for(re int i=1;i<=vc;i++)
		{
			re int x=p[1];
			std::pop_heap(p+1,p+m+1,cmp);
			b[x]--;
			std::push_heap(p+1,p+m+1,cmp);
		}
		for(re int i=1;i<=m;i++)mi=std::min(mi,a[i]/b[i]);
		for(re int i=1;i<=m;i++)p1[i]=i;
		std::sort(p1+1,p1+m+1,cmp1);
		for(re int i=1;i<=m;i++)
		{
			re int x=p1[i],y=p[1];
			ans=std::min(ans,std::max((a[x]+b[x]-1)/b[x],mx)-mi);
			if(b[y]==1||(a[x]+b[x]-1)/b[x]<=(a[y]+b[y]-2)/(b[y]-1))break;
			std::pop_heap(p+1,p+m+1,cmp);
			b[y]--;b[x]++;
			mi=std::min(mi,a[x]/b[x]);mx=std::max(mx,(a[y]+b[y]-1)/b[y]);
			std::push_heap(p+1,p+m+1,cmp);
		}
		printf("%lld\n",ans);
	}
}