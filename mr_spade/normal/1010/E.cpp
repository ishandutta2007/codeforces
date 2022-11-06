#include<cstdio>
#include<algorithm>
using std::max;
using std::min;
using std::inplace_merge;
using std::sort;
const int N=1e6+5;
int n,m,k,tot,idx,xm,ym,zm;
int xl,xr,yl,yr,zl,zr;
struct cell
{
	int opt,id;
	int x,y,z;
}c[N];
int ans[N],res[N];
int bit[N];
inline void add(int x,int k)
{
	while(x<=zm)
		bit[x]+=k,x+=x&-x;
	return;
}
inline int ask(int x)
{
	int res=0;
	while(x)
		res+=bit[x],x-=x&-x;;
	return res;
}
inline bool cmpx(cell a,cell b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.opt<b.opt;
}
inline bool cmpy(cell a,cell b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.opt<b.opt;
}
void solve(int l,int r)
{
	if(l>=r)
		return;
	int mid=(l+r)>>1;
	register int i,j;
	solve(l,mid);solve(mid+1,r);
	i=l;j=mid+1;
	while(i<=mid&&j<=r)
		if(c[i].y<=c[j].y)
		{
			if(c[i].opt==1)
				add(c[i].z,1);
			i++;
		}
		else
		{
			if(c[j].opt==2)
				ans[c[j].id]+=ask(c[j].z);
			j++;
		}
	while(i<=mid)
	{
		if(c[i].opt==1)
			add(c[i].z,1);
		i++;
	}
	while(j<=r)
	{
		if(c[j].opt==2)
			ans[c[j].id]+=ask(c[j].z);
		j++;
	}
	for(i=l;i<=mid;i++)
		if(c[i].opt==1)
			add(c[i].z,-1);
	inplace_merge(c+l,c+mid+1,c+r+1,cmpy);
	return;
}
signed main()
{
	int x,y,z;
	register int i,j;
	scanf("%d%d%d",&xm,&ym,&zm);
	scanf("%d%d%d",&n,&m,&k);
	xl=xm;yl=ym;zl=zm;
	xr=yr=zr=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(xl>x)
			xl=x;
		if(yl>y)
			yl=y;
		if(zl>z)
			zl=z;
		if(xr<x)
			xr=x;
		if(yr<y)
			yr=y;
		if(zr<z)
			zr=z;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x>=xl&&x<=xr&&y>=yl&&y<=yr&&z>=zl&&z<=zr)
			return puts("INCORRECT"),0;
		c[++tot]=cell{1,0,x,y,z};
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x>=xl&&x<=xr&&y>=yl&&y<=yr&&z>=zl&&z<=zr)
		{
			res[i]=1;
			continue;
		}
		c[++tot]=cell{2,++idx,max(xr,x),max(yr,y),max(zr,z)};
		c[++tot]=cell{2,++idx,min(xl,x)-1,max(yr,y),max(zr,z)};
		c[++tot]=cell{2,++idx,max(xr,x),min(yl,y)-1,max(zr,z)};
		c[++tot]=cell{2,++idx,max(xr,x),max(yr,y),min(zl,z)-1};
		c[++tot]=cell{2,++idx,min(xl,x)-1,min(yl,y)-1,max(zr,z)};
		c[++tot]=cell{2,++idx,min(xl,x)-1,max(yr,y),min(zl,z)-1};
		c[++tot]=cell{2,++idx,max(xr,x),min(yl,y)-1,min(zl,z)-1};
		c[++tot]=cell{2,++idx,min(xl,x)-1,min(yl,y)-1,min(zl,z)-1};
	}
	sort(c+1,c+tot+1,cmpx);
	solve(1,tot);
	puts("CORRECT");
	idx=0;
	for(i=1;i<=k;i++)
		if(!res[i])
		{
			res[i]+=ans[++idx];
			for(j=0;j<3;j++)
				res[i]-=ans[++idx];
			for(j=0;j<3;j++)
				res[i]+=ans[++idx];
			res[i]-=ans[++idx];
			if(!res[i])
				res[i]=3;
			else
				res[i]=2;
		}
	for(i=1;i<=k;i++)
		switch(res[i])
		{
			case 1:puts("OPEN");break;
			case 2:puts("CLOSED");break;
			case 3:puts("UNKNOWN");break;
		}
	return 0;
}