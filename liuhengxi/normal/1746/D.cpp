#include<cstdio>
#include<utility>
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
constexpr int N=2e5+5;
int s[N];
vector<int> adj[N];
pair<long long,long long> dfs(int u,int k)
{
	if(adj[u].empty())return {(long long)k*s[u],(k+1ll)*s[u]};
	int kc=k/(int)adj[u].size(),km=k%(int)adj[u].size();
	vector<pair<long long,long long>> res;
	pair<long long,long long> ans;
	for(int v:adj[u])res.emplace_back(dfs(v,kc));
	sort(res.begin(),res.end(),[](pair<long long,long long>a,pair<long long,long long>b)
	{return a.second-a.first>b.second-b.first;});
	ans.first=k*(long long)s[u];
	for(auto xy:res)ans.first+=xy.first;
	F(i,0,km)ans.first+=res[i].second-res[i].first;
	ans.second=ans.first+res[km].second-res[km].first+s[u];
	return ans;
}
int tt,n,k;
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,k);
		F(i,1,n)
		{
			int p;
			adj[--read(p)].emplace_back(i);
		}
		F(i,0,n)read(s[i]);
		pair<long long,long long> ans=dfs(0,k);
		printf("%lld\n",ans.first);
		F(i,0,n)adj[i].clear();
	}
	return 0;
}