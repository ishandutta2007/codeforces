#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define getlc int lc=p<<1
#define getrc int rc=p<<1|1
#define getmid int mid=(l+r)>>1
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,col[N<<2],tag[N<<2];
long long sum[N<<2],delta[N<<2];
bool same[N<<2];
inline void pushup(int p)
{
	getlc;getrc;
	same[p]=same[lc]&&same[rc]&&col[lc]==col[rc];
	col[p]=col[lc];
	sum[p]=sum[lc]+sum[rc];
}
inline void pushdown(int p,int l,int r)
{
	if(!tag[p])return;
	getmid;getlc;getrc;
	delta[lc]+=delta[p];delta[rc]+=delta[p];
	sum[lc]+=delta[p]*(mid-l);sum[rc]+=delta[p]*(r-mid);
	tag[lc]=tag[p];col[lc]=tag[p];
	tag[rc]=tag[p];col[rc]=tag[p];
	tag[p]=delta[p]=0;
}
void build(int p,int l,int r)
{
	getmid;
	if(r-l==1)return col[p]=l+1,sum[p]=0,same[p]=true,void();
	getlc;getrc;
	build(lc,l,mid);build(rc,mid,r);
	pushup(p);
}
void update(int p,int l,int r,int x,int y,int c)
{
	getmid;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y&&same[p])
	{
		int d=col[p]>c?col[p]-c:c-col[p];
		sum[p]+=(long long)(r-l)*d,col[p]=tag[p]=c,delta[p]+=d;
		return;
	}
	pushdown(p,l,r);
	update(p<<1,l,mid,x,y,c);update(p<<1|1,mid,r,x,y,c);
	pushup(p);
}
long long query(int p,int l,int r,int x,int y)
{
	if(y<=l||r<=x)return 0;
	if(x<=l&&r<=y)return sum[p];
	getmid;pushdown(p,l,r);
	return query(p<<1,l,mid,x,y)+query(p<<1|1,mid,r,x,y);
}
int main()
{
	read(n);read(m);
	build(1,0,n);
	while(m--)
	{
		int type,l,r,x;read(type);
		if(type==1)
		{
			read(l);read(r);read(x);--l;
			update(1,0,n,l,r,x);
		}
		else
		{
			read(l);read(r);--l;
			printf("%lld\n",query(1,0,n,l,r));
		}
	}
	return 0;
}