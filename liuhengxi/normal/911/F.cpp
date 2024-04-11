#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int n,hd[N],cnt,a,b,dep[N],depa[N],depb[N],id[N];
long long ans;
bool cmp(int u,int v){return depa[u]+depb[u]!=depa[v]+depb[v]?depa[u]+depb[u]>depa[v]+depb[v]:depa[u]>depa[v];}
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
int main()
{
	F(i,0,read(n))hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;--read(u);--read(v);
		adline(u,v);adline(v,u);
	}
	dep[0]=0;
	dfs(0,0);
	F(i,0,n)if(dep[i]>dep[a])a=i;
	dep[a]=0;
	dfs(a,a);
	F(i,0,n)if((depa[i]=dep[i])>dep[b])b=i;
	dep[b]=0;
	dfs(b,b);
	F(i,0,n)depb[i]=dep[i];
	F(i,0,n)id[i]=i;
	sort(id,id+n,cmp);
	F(i,0,n-1)
	{
		int u=id[i];
		if(depa[u]+depb[u]==depa[b])ans+=depa[u];
		else ans+=max(depa[u],depb[u]);
	}
	printf("%lld\n",ans);
	F(i,0,n-1)
	{
		int u=id[i];
		if(depa[u]+depb[u]==depa[b])printf("%d %d %d\n",u+1,a+1,u+1);
		else printf("%d %d %d\n",u+1,depa[u]>depb[u]?a+1:b+1,u+1);
	}
	return 0;
}