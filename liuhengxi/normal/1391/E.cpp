#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5,M=1e6+5;
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
}e[2*M];
int tt,n,m,hd[N],cnt,dep[N],last[N],fa[N];
bool vis[N];
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	vis[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(vis[v])continue;
		dep[v]=dep[fa[v]=u]+1;
		dfs(v);
	}
}
int main()
{
	for(read(tt);tt--;)
	{
		int lim;bool path=false;
		read(n,m);lim=(n>>1)+(n&1);
		F(i,cnt=0,n)hd[i]=-1,vis[i]=false;
		F(i,0,m)
		{
			int u,v;--read(u);--read(v);
			adline(u,v);adline(v,u);
		}
		dfs(0);fa[0]=-1;
		F(i,0,n)if(dep[i]+1>=lim)
		{
			puts("PATH");
			printf("%d\n",dep[i]+1);
			for(int u=i;~u;u=fa[u])printf("%d ",u+1);
			puts("");
			path=true;break;
		}
		if(!path)
		{
			F(i,0,lim)last[i]=-1;
			puts("PAIRING");
			lim+=lim&1;
			printf("%d\n",lim>>=1);
			F(i,0,n)last[dep[i]]=~last[dep[i]]&&lim?--lim,printf("%d %d\n",last[dep[i]]+1,i+1),-1:i;
		}
	}
	return 0;
}