#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=1e4+5;
int n,m,dep[N],even[N],odd[N],occ,oddc[N],evenc[N];
bool vis[N],ans[N];
vector<pair<int,int>> adj[N];
void dfs(int u,int fa,int from)
{
	#define v vi.first
	#define i vi.second
	vis[u]=true;
	for(pair<int,int> vi:adj[u])if(v!=fa)
	{
		if(vis[v])
		{
			if(dep[v]<dep[u])
			{
				if((dep[u]^dep[v])&1)++even[u],--even[v],evenc[i]=1;
				else ++occ,++odd[u],--odd[v],oddc[i]=1;
			}
		}
		else dep[v]=dep[u]+1,dfs(v,u,i),odd[u]+=odd[v],even[u]+=even[v];
	}
	#undef v
	#undef i
	if(~from)oddc[from]=odd[u],evenc[from]=even[u];
}
int main()
{
	read(n,m);
	F(i,0,m)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v,i);
		adj[v].emplace_back(u,i);
	}
	F(i,0,n)if(!vis[i])dfs(i,i,-1);
	if(occ)
	{
		int cnt=0;
		F(i,0,m)if(oddc[i]==occ&&!evenc[i])++cnt;
		printf("%d\n",cnt);
		F(i,0,m)if(oddc[i]==occ&&!evenc[i])printf("%d ",i+1);
		puts("");
	}
	else
	{
		printf("%d\n",m);
		F(i,1,m+1)printf("%d ",i);
		puts("");
	}
	return 0;
}