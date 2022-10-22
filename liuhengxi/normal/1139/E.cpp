#include<cstdio>
#include<vector>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005;
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
int n,m,p[N],c[N],d,k[N],ans[N],ma[N],cur,vis[N],tm;
vector<int> adj[N];
bool o[N];
void add(int x)
{
	auto &tmp=adj[p[x]];
	if(find(tmp.begin(),tmp.end(),c[x])==tmp.end())tmp.emplace_back(c[x]);
}
bool dfs(int u)
{
	if(vis[u]==tm)return false;
	vis[u]=tm;
	for(int v:adj[u])
	{
		if(!~ma[v])
		{
			ma[v]=u;
			return true;
		}
		int t=ma[v];
		ma[v]=u;
		if(dfs(t))return true;
		ma[v]=t;
	}
	return false;
}
int main()
{
	read(n,m);
	F(i,0,n)read(p[i]);
	F(i,0,n)--read(c[i]);
	F(i,0,m)ma[i]=-1;
	F(i,0,n)o[i]=true;
	F(i,0,read(d))o[--read(k[i])]=false;
	F(i,0,n)if(o[i])add(i);
	for(int i=d;~--i;)
	{
		while(++tm,dfs(cur))++cur;
		ans[i]=cur;
		add(k[i]);
	}
	F(i,0,d)printf("%d\n",ans[i]);
	return 0;
}