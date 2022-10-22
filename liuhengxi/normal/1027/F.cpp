#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define quit return puts("-1"),0
using namespace std;
const int N=1e6+5,M=2e6+5;
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
}e[2*N];
int n,m,a[N],b[N],val[M],hd[M],cnt,f[M],ndcnt[M],lncnt[M],ans,fsb;
bool busy[M];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs1(int u,int fa)
{
	ans=max(ans,val[u]);
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs1(v,u);
	}
}
void dfs2(int u,int fa)
{
	fsb=max(fsb,val[u]);
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs2(v,u);
	}
}
void dfs3(int u,int fa)
{
	if(val[u]==fsb)++fsb;
	else ans=max(ans,val[u]);
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs3(v,u);
	}
}
int main()
{
	F(i,0,read(n))val[i<<1]=read(a[i]),val[i<<1|1]=read(b[i]);
	sort(val,val+(n<<1));m=unique(val,val+(n<<1))-val;
	F(i,0,m)f[i]=i,hd[i]=-1;
	F(i,0,n)a[i]=lower_bound(val,val+m,a[i])-val,b[i]=lower_bound(val,val+m,b[i])-val;
	F(i,0,n)if(find(a[i])!=find(b[i]))f[f[a[i]]]=f[b[i]],adline(a[i],b[i]),adline(b[i],a[i]);
	F(i,0,m)++ndcnt[find(i)];
	F(i,0,n)++lncnt[find(a[i])];
	F(i,0,m)if(f[i]==i)
	{
		if(lncnt[i]>ndcnt[i])quit;
		if(lncnt[i]==ndcnt[i])dfs1(i,i);
		if(lncnt[i]<ndcnt[i])fsb=0,dfs2(i,i),dfs3(i,i);
	}
	printf("%d\n",ans);
	return 0;
}