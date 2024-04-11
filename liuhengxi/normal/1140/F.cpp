#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=3e5+5,M=1e7+5;
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
struct line{int next,to;}e[M];
int n,x[N],y[N],v[N<<1],f[N<<1],sx[N<<1],sy[N<<1],tx[N],ty[N],p,last[N],hd[N<<2],cnt;
long long h[N],vv[N],ans;
int find(int x){return f[x]==x?x:find(f[x]);}
inline void merge(int x,int y)
{
	if((x=find(x))==(y=find(y)))return tx[p++]=-1,void();
	if(sx[x]+sy[x]<sx[y]+sy[y])swap(x,y);
	tx[p]=x,ty[p++]=y;
	f[y]=x;
	ans+=sx[x]*(long long)sy[y]+sy[x]*(long long)sx[y];
	sx[x]+=sx[y],sy[x]+=sy[y];
}
inline void undo()
{
	if(~tx[--p])
	{
		int &x=tx[p],&y=ty[p];
		sx[x]-=sx[y],sy[x]-=sy[y];
		ans-=sx[x]*(long long)sy[y]+sy[x]*(long long)sx[y];
		f[y]=y;
	}
}
inline void adline(int u,int v){e[cnt].to=v;e[cnt].next=hd[u];hd[u]=cnt++;}
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	hd[p]=-1;
	if(r-l==1)return;
	build(lc,l,mid);build(rc,mid,r);
}
void update(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return adline(p,v);
	update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
}
void dfs(int p,int l,int r)
{
	int mid=(l+r)>>1;
	for(int i=hd[p];~i;i=e[i].next)merge(x[e[i].to],y[e[i].to]);
	if(r-l==1)printf("%lld ",ans);
	else{dfs(lc,l,mid);dfs(rc,mid,r);}
	for(int i=hd[p];~i;i=e[i].next)undo();
}
int main()
{
	F(i,0,read(n))read(x[i],y[i]);
	F(i,0,n)v[i]=x[i],v[i+n]=y[i];
	sort(v,v+n);sort(v+n,v+n+n);
	F(i,0,n)vv[i]=h[i]=(long long)(x[i]=lower_bound(v,v+n,x[i])-v)<<20|(y[i]=lower_bound(v+n,v+n+n,y[i])-v);
	sort(vv,vv+n);
	F(i,0,n)h[i]=lower_bound(vv,vv+n,h[i])-vv;
	F(i,0,n)last[i]=-1;
	build(1,0,n);
	F(i,0,n)last[h[i]]=~last[h[i]]?(update(1,0,n,last[h[i]],i,i),-1):i;
	F(i,0,n)if(last[h[i]]==i)update(1,0,n,i,n,i);
	F(i,0,n)sx[f[i]=i]=1;
	F(i,n,n+n)sy[f[i]=i]=1;
	dfs(1,0,n);
	puts("");
	return 0;
}