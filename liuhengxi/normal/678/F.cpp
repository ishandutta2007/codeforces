#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
typedef long long ll;
const int N=3e5+5;
const ll LLINF=0x3fffffffffffffffll;
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
struct line
{
	int next,to;
}e[N<<6];
int m,x[N],y[N],n,l[N],r[N],qy[N],hd[N<<2],cnt,id[N],sta[N],top;
long long ans[N];
bool cmp1(int u,int v){return x[u]>x[v];}
bool cmp2(int u,int v){return qy[u]<qy[v];}
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
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
	for(int i=hd[p];~i;i=e[i].next)
	{
#define u sta[top-2]
#define v sta[top-1]
		int w=e[i].to;
		while(top>=2&&ll(y[v]-y[u])*(x[w]-x[v])<=ll(y[w]-y[v])*(x[v]-x[u]))--top;
		sta[top++]=w;
#undef u
#undef v
	}
	hd[p]=-1;
	while(top)adline(p,sta[--top]);
	if(r-l==1)return;
	dfs(lc,l,mid);dfs(rc,mid,r);
}
long long query(int p,int l,int r,int z)
{
	int mid=(l+r)>>1;
	long long ans=-LLINF,k=qy[z];
#define u e[hd[p]].to
#define v e[e[hd[p]].next].to
	if(~hd[p])
	{
		while(~e[hd[p]].next&&y[u]+k*x[u]<y[v]+k*x[v])hd[p]=e[hd[p]].next;
		ans=y[u]+k*x[u];
	}
#undef u
#undef v
	if(r-l==1)return ans;
	if(z<mid)return max(query(lc,l,mid,z),ans);
	else return max(query(rc,mid,r,z),ans);
}
int main()
{
	read(m);
	F(i,0,m)l[i]=-1,r[i]=-1;
	F(i,0,m)
	{
		int t;read(t);
		if(t==1)read(x[i],y[i]),l[i]=n;
		if(t==2)
		{
			int k;
			r[--read(k)]=n;
		}
		if(t==3)read(qy[n++]);
	}
	F(i,0,m)if(~l[i]&&!~r[i])r[i]=n;
	if(n==0)return 0;
	build(1,0,n);
	F(i,0,m)id[i]=i;
	sort(id,id+m,cmp1);
	F(i,0,m)
	{
		int u=id[i];
		if(~l[u])update(1,0,n,l[u],r[u],u);
	}
	F(i,0,n)id[i]=i;
	dfs(1,0,n);
	sort(id,id+n,cmp2);
	F(i,0,n)ans[id[i]]=query(1,0,n,id[i]);
	F(i,0,n)if(ans[i]==-LLINF)puts("EMPTY SET");else printf("%lld\n",ans[i]);
	return 0;
}