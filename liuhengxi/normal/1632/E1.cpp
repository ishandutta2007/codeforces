#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
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
struct line
{
	int next,to;
}e[2*N];
int tt,n,hd[N],cnt,ans[N],dep[N],d1[N],d2[N];
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	d1[u]=d2[u]=-1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		if(d1[v]>d1[u])d2[u]=d1[u],d1[u]=d1[v];
		else if(d1[v]>d2[u])d2[u]=d1[v];
	}
	if(!~d1[u])d1[u]=dep[u];
	else if(!~d2[u])d2[u]=dep[u];
	if(~d2[u])F(x,1,n+1)ans[x]=max(ans[x],min(d2[u],((d1[u]+d2[u]+1)>>1)-dep[u]+x));
	F(x,1,n+1)ans[x]=max(ans[x],min(dep[u],x));
}
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n+1)ans[i]=0;
		F(i,cnt=0,n)hd[i]=-1;
		F(i,0,n-1)
		{
			int u,v;--read(u),--read(v);
			adline(u,v);adline(v,u);
		}
		dfs(0,0);
		F(i,1,n+1)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}