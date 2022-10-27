// LUOGU_RID: 90668396
#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int A=1e6,sqrA=A*A;
unordered_set<int>s;
vector<pair<int,int>>e[100001];
int X[100001],Y[100001];
int ans[100001];
void dfs(int p,int k,int fa)
{
	ans[p]=k;
	for(auto q:e[p])
	if(q.first!=fa)
	dfs(q.first,q.second*k,p);
}
main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	//freopen("circle.in","r",stdin);freopen("circle.out","w",stdout);
	auto calc=[&](int x,int y){return x*x+y*y;};
	int n;
	cin>>n;
	for(int x=1;x<=n;x++)
	cin>>X[x]>>Y[x],s.insert(x);
	while(s.size()>=2)
	{
		for(auto it=s.begin();it!=s.end();it++)
		{
			auto it2=it;
			it2++;
			for(;it2!=s.end();it2++)
			{
				int v1=*it,v2=*it2;
				if(calc(X[v1]+X[v2],Y[v1]+Y[v2])<=sqrA+(s.size()==2)*sqrA)
				{
					e[v2].push_back({v1,1});
					e[v1].push_back({v2,1});
					s.erase(it2);
					X[v1]+=X[v2];
					Y[v1]+=Y[v2];
					goto nxt;
				}
				if(calc(X[v1]-X[v2],Y[v1]-Y[v2])<=sqrA+(s.size()==2)*sqrA)
				{
					e[v2].push_back({v1,-1});
					e[v1].push_back({v2,-1});
					s.erase(it2);
					X[v1]-=X[v2];
					Y[v1]-=Y[v2];
					goto nxt;
				}
			}
		}
		nxt:;
	}
	ans[0]=1;
	dfs(1,1,0);
	for(int x=1;x<=n;x++)
	cout<<ans[x]<<' ';
}