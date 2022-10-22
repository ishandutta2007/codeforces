// LUOGU_RID: 90534837
#include<cstdio>
#include<vector>
#include<map>
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
typedef unsigned long long ull;
ull hh(ull x){return 8181*x*x*x+168*x*x+891;}
ull f(ull x){return hh(x>>13^x>>37)+hh(x);}
constexpr int N=1e5+5;
int n,ans,cur,ansu;
ull h[N];
vector<int> adj[N];
map<ull,int> mp;
void dfsa(int u,int fa)
{
	h[u]=1;
	for(int v:adj[u])if(v!=fa)
	{
		dfsa(v,u);
		h[u]+=f(h[v]);
	}
}
void dfsb(int u,int fa)
{
	if(cur>ans)ans=cur,ansu=u;
	for(int v:adj[u])if(v!=fa)
	{
		cur-=!--mp[h[u]];cur-=!--mp[h[v]];
		h[u]-=f(h[v]);
		h[v]+=f(h[u]);
		cur+=1==++mp[h[u]];cur+=1==++mp[h[v]];
		dfsb(v,u);
		cur-=!--mp[h[u]];cur-=!--mp[h[v]];
		h[v]-=f(h[u]);
		h[u]+=f(h[v]);
		cur+=1==++mp[h[u]];cur+=1==++mp[h[v]];
	}
}
int main()
{
	read(n);
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfsa(0,0);
	F(i,0,n)if(1==++mp[h[i]])++cur;
	ans=cur;
	dfsb(0,0);
	printf("%d\n",ansu+1);
	return 0;
}