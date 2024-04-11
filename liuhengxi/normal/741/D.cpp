#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
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
constexpr int N=5e5+5,M=(1<<22)+5,INF=0x3f3f3f3f;
int n,p[N],s[N],siz[N],mc[N],hc[N],mx[M],ans[N],dep[N];
char c[N][2];bool h[N];
vector<int> adj[N];
vector<pair<int,int>> val[N];
void dfs(int u)
{
	if(!~hc[u])
	{
		val[u].emplace_back(s[u],dep[u]);
		mx[s[u]]=dep[u];
	}
	else
	{
		for(int v:adj[u])if(v!=hc[u])
		{
			dep[v]=dep[u]+1;
			dfs(v);
			ans[u]=max(ans[u],ans[v]);
		}
		{
			int v=hc[u];
			dep[v]=dep[u]+1;
			dfs(v);
			ans[u]=max(ans[u],ans[v]);
			val[u]=move(val[v]);
			ans[u]=max(ans[u],mx[s[u]]-dep[u]);
			F(i,0,22)ans[u]=max(ans[u],mx[s[u]^1<<i]-dep[u]);
			mx[s[u]]=max(mx[s[u]],dep[u]);
			val[u].emplace_back(s[u],dep[u]);
		}
		for(int v:adj[u])if(v!=hc[u])
		{
			for(auto x:val[v])
			{
				ans[u]=max(ans[u],mx[x.first]+x.second-(dep[u]<<1));
				F(i,0,22)ans[u]=max(ans[u],mx[x.first^1<<i]+x.second-(dep[u]<<1));
				val[u].emplace_back(x);
			}
			for(auto x:val[v])mx[x.first]=max(mx[x.first],x.second);
		}
	}
	if(!h[u])for(auto x:val[u])mx[x.first]=-INF;
}
int main()
{
	memset(mx,-0x3f,sizeof mx);
	read(n);
	F(i,1,n)adj[--read(p[i])].emplace_back(i),scanf("%s",c[i]),s[i]=s[p[i]]^1<<(c[i][0]-'a');
	for(int i=n;--i;)siz[p[i]]+=++siz[i],mc[p[i]]=max(mc[p[i]],siz[i]);
	++siz[0];
	F(i,0,n)hc[i]=-1;
	for(int i=n;--i;)if(mc[p[i]]==siz[i])mc[p[i]]=-1,hc[p[i]]=i,h[i]=true;
	dfs(0);
	F(i,0,n)printf("%d ",ans[i]);
	puts("");
	return 0;
}