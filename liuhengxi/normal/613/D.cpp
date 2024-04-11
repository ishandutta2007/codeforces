#include<cstdio>
#include<vector>
#include<set>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int n,ans[N],id[N],m;
vector<int> adj[N];
set<int> s[N],del;
void dfs2(int u,int fa)
{
	for(int v:adj[u])if(v!=fa)
	{
		if(s[u].size()>s[v].size())
		{
			for(int x:s[v])if(s[u].count(x))ans[x]=n<<1;
		}
		else
		{
			for(int x:s[u])if(s[v].count(x))ans[x]=n<<1;
		}
		dfs2(v,u);
	}
	for(int i=0,t=(int)adj[u].size();i<t;++i)if(adj[u][i]==fa)
	{
		for(int j=i;j<t-1;++j)adj[u][j]=adj[u][j+1];
		adj[u].pop_back();
		break;
	}
}
void dfs(int u)
{
	int h=u;
	for(int v:adj[u])
	{
		dfs(v);
		if(s[id[v]].size()>s[id[h]].size())h=v;
	}
	if(h==u)
	{
		for(int v:adj[u])
		{
			for(int x:s[id[v]])if(s[u].count(x))del.insert(x);
			for(int x:del)s[id[v]].erase(x),++ans[x];
			del.clear();
		}
		for(int v:adj[u])
		{
			for(int x:s[id[v]])if(s[u].count(x))del.insert(x);
			else s[u].insert(x);
		}
		for(int x:del)s[u].erase(x),++ans[x];
		del.clear();
	}
	else
	{
		id[u]=id[h];
		for(int v:adj[u])if(v!=h)
		{
			for(int x:s[id[v]])if(s[u].count(x))del.insert(x);
			for(int x:del)s[id[v]].erase(x),++ans[x];
			del.clear();
		}
		for(int x:s[u])if(s[id[h]].count(x))del.insert(x);
		for(int x:del)s[id[h]].erase(x),++ans[x];
		del.clear();
		for(int v:adj[u])if(v!=h)
		{
			for(int x:s[id[v]])if(s[id[h]].count(x))del.insert(x);
			else s[id[h]].insert(x);
		}
		for(int x:s[u])if(s[id[h]].count(x))del.insert(x);
		else s[id[h]].insert(x);
		for(int x:del)s[id[h]].erase(x),++ans[x];
		del.clear();
	}
}
int main()
{
	read(n);
	F(i,0,n-1)
	{
		int u,v;--read(u),--read(v);
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	F(i,0,n)id[i]=i;
	read(m);
	F(i,0,m)
	{
		int t,u;read(t);
		while(t--)s[--read(u)].emplace(i);
	}
	dfs2(0,0);
	dfs(0);
	F(i,0,m)(ans[i]>n&&(ans[i]=-1)),printf("%d\n",ans[i]);
	return 0;
}