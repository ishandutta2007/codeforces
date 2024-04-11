#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)+1)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,q,a[N],min[N<<2],tag[N<<2];
long long sum[N<<2];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	min[p]=a[r-1];
	if(r-l==1)return sum[p]=a[l],void();
	build(lc,l,mid);build(rc,mid,r);
	sum[p]=sum[lc]+sum[rc];
}
void update(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)
	{
		sum[p]=v*(long long)(r-l);
		tag[p]=min[p]=v;
		return;
	}
	if(tag[p])
	{
		sum[lc]=tag[p]*(long long)(mid-l);
		sum[rc]=tag[p]*(long long)(r-mid);
		min[lc]=tag[lc]=tag[p];
		min[rc]=tag[rc]=tag[p];
		tag[p]=0;
	}
	update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
	min[p]=min[rc];sum[p]=sum[lc]+sum[rc];
}
long long query_sum(int p,int l,int r,int x)
{
	int mid=(l+r)>>1;
	if(r<=x)return sum[p];
	if(l>=x)return 0;
	if(tag[p])
	{
		sum[lc]=tag[p]*(long long)(mid-l);
		sum[rc]=tag[p]*(long long)(r-mid);
		min[lc]=tag[lc]=tag[p];
		min[rc]=tag[rc]=tag[p];
		tag[p]=0;
	}
	return query_sum(lc,l,mid,x)+query_sum(rc,mid,r,x);
}
int find_first(int p,int l,int r,long long lim,bool pre)// find the first number <= lim  prefixsum > lim
{
	int mid=(l+r)>>1;
	if(r-l==1)return (pre?sum[p]>lim:min[p]<=lim)?l:r;
	if(tag[p])
	{
		sum[lc]=tag[p]*(long long)(mid-l);
		sum[rc]=tag[p]*(long long)(r-mid);
		min[lc]=tag[lc]=tag[p];
		min[rc]=tag[rc]=tag[p];
		tag[p]=0;
	}
	if((pre?sum[lc]>lim:min[lc]<=lim))return find_first(lc,l,mid,lim,pre);
	return find_first(rc,mid,r,lim-(pre?sum[lc]:0),pre);
}
int main()
{
	read(n);read(q);
	F(i,0,n)read(a[i]);
	build(1,0,n);
	while(q--)
	{
		int t,x,y;read(t);read(x);read(y);x-=t-1;
		if(t==1)
		{
			int pos=find_first(1,0,n,y,false);
			if(pos<x)update(1,0,n,pos,x,y);
		}
		else
		{
			int ans=0;
			for(int now=x;now!=n;)
			{
				int left=find_first(1,0,n,y,false);if(left<now)left=now;
				long long zhimao=query_sum(1,0,n,left);
				int right=find_first(1,0,n,zhimao+y,true);
				y-=query_sum(1,0,n,right)-zhimao;
				ans+=right-left;
				now=right;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}