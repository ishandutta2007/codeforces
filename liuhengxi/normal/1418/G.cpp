#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=5e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,m,a[N],last[N],nxt[N],mv[N<<2],mc[N<<2],tag[N<<2];
long long ans;
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	mc[p]=r-l;
	if(r-l==1)return;
	build(lc,l,mid);build(rc,mid,r);
}
inline void update(int p,int x){tag[p]+=x;mv[p]+=x;}
inline void pushdown(int p){update(lc,tag[p]);update(rc,tag[p]);tag[p]=0;}
inline void pushup(int p){mv[p]=min(mv[lc],mv[rc]);mc[p]=(mv[p]==mv[lc]?mc[lc]:0)+(mv[p]==mv[rc]?mc[rc]:0);}
void update(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return update(p,v);
	pushdown(p);
	update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
	pushup(p);
}
void proc(int x,int y)
{
	update(1,0,m,x+1,m,y);
	if(!~nxt[x])return;else x=nxt[x];
	if(!~nxt[x])return;else x=nxt[x];
	update(1,0,m,x+1,m,-y);
	if(!~nxt[x])return;else x=nxt[x];
	update(1,0,m,x+1,m,y);
}
int main()
{
	F(i,0,read(n))--read(a[i]);
	F(i,0,n)last[i]=-1;
	m=n+1;
	build(1,0,m);
	for(int i=n;~--i;)
	{
		nxt[i]=last[a[i]],last[a[i]]=i;
		if(~nxt[i])proc(nxt[i],-1);
		proc(i,1);
		ans+=mc[1]-i-1;
	}
	printf("%lld\n",ans);
	return 0;
}