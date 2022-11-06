#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using std::min;
using std::max;
using std::swap;
const int N=1e5+5,inf=0x3f3f3f3f;
int n,q,m,idx;
int a[N],f[N];
int bl[N],tag[N],bd[N],lp[N],rp[N];
int bk[N];
inline void rebuild(int t)
{
	register int i;
	for(i=lp[t];i<=rp[t];i++)
		a[i]=max(a[i]-tag[t],1);
	bd[t]=inf;tag[t]=0;
	for(i=lp[t];i<=rp[t];i++)
		bd[t]=min(bd[t],i-a[i]);
	for(i=lp[t];i<=rp[t];i++)
	{
		if(bl[a[i]]==bl[i])
			f[i]=f[a[i]];
		else
			f[i]=i;
	}
	return;
}
inline int lca(int x,int y)
{
	while(f[x]!=f[y])
	{
		if(bl[x]>bl[y])
			swap(x,y);
		y=max(a[f[y]]-tag[bl[y]],1);
	}
	idx++;
	for(;bl[x]==bl[y];x=x==1?0:max(a[x]-tag[bl[x]],1))
		bk[x]=idx;
	for(;bk[y]!=idx;y=max(a[y]-tag[bl[y]],1));
	return y;
}
signed main()
{
	int opt,l,r,x;
	register int i,j;
	scanf("%d%d",&n,&q);
	a[1]=1;
	for(i=2;i<=n;i++)
		scanf("%d",&a[i]);
	m=(int)(sqrt(n)+4);
	for(i=1;i<=n;i++)
		bl[i]=(i-1)/m+1,rp[bl[i]]=i;
	memset(bd,0x3f,sizeof(bd));
	for(i=n;i>=1;i--)
		bd[bl[i]]=min(bd[bl[i]],i-a[i]),lp[bl[i]]=i;
	f[1]=1;
	for(i=1;i<=n;i++)
		if(bl[a[i]]!=bl[i])
			f[i]=i;
		else
			f[i]=f[a[i]];
	while(q--)
	{
		if(scanf("%d",&opt),opt==1)
		{
			scanf("%d%d%d",&l,&r,&x);
			if(bl[l]==bl[r])
			{
				for(i=l;i<=r;i++)
					a[i]-=x;
				rebuild(bl[l]);
			}
			else
			{
				for(i=l;i<=rp[bl[l]];i++)
					a[i]-=x;
				rebuild(bl[l]);
				for(i=bl[l]+1;i<=bl[r]-1;i++)
					if(bd[i]<m)
						tag[i]=min(tag[i]+x,n),rebuild(i);
					else
						tag[i]=min(tag[i]+x,n);
				for(i=lp[bl[r]];i<=r;i++)
					a[i]-=x;
				rebuild(bl[r]);
			}
		}
		else
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",lca(l,r));
		}
	}
	return 0;
}