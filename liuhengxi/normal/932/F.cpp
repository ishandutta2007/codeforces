#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
const long long LLINF=0x3fffffffffffffff;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct edge{int next,to;}e[2*N];
struct line{long long k,b;long long operator()(int x){return k*x+b;}}s[N<<7];
int n,a[N],b[N],hd[N],cnt,id,ls[N],rs[N],sta[N],top;
long long f[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int build(line x){int p=top?sta[--top]:++id;s[p]=x;ls[p]=0,rs[p]=0;return p;}
int merge(int p,int q,int l=-N,int r=N)
{
	int mid=(l+r)>>1;
	if(!p||!q)return p|q;
	if(s[p](mid)>s[q](mid))swap(p,q);
	ls[p]=merge(ls[p],ls[q],l,mid);
	rs[p]=merge(rs[p],rs[q],mid,r);
	if(s[q](l)<s[p](l))ls[p]=merge(ls[p],build(s[q]),l,mid);
	if(s[q](r)<s[p](r))rs[p]=merge(rs[p],build(s[q]),mid,r);
	sta[top++]=q;
	if(r-l==1)ls[p]=rs[p]=0;
	return p;
}
long long query(int p,int x,int l=-N,int r=N)
{
	int mid=(l+r)>>1;
	long long ans;
	if(!p)return LLINF;
	if(x<mid)ans=query(ls[p],x,l,mid);
	else ans=query(rs[p],x,mid,r);
	ans=min(ans,s[p](x));
	return ans;
}
int dfs(int u,int fa)
{
	int rt=0,ch=0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		rt=merge(rt,dfs(v,u));
		++ch;
	}
	if(!ch)f[u]=0;
	else f[u]=query(rt,a[u]);
	rt=merge(rt,build(line{b[u],f[u]}));
	return rt;
}
int main()
{
	read(n);
	F(i,0,n)hd[i]=-1;
	F(i,0,n)read(a[i]);
	F(i,0,n)read(b[i]);
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adline(u,v);adline(v,u);
	}
	dfs(0,0);
	F(i,0,n)printf("%lld ",f[i]);
	puts("");
	return 0;
}