#include<iostream>
#include<vector>
#include<set>
using namespace std;
int N,A[2<<17];
vector<int>G[2<<17];
int ans=0;
int rv;
set<int>ret;
void dfs(int u,int p)
{
	int nv=0;
	set<int>now;
	now.insert(0);
	bool fn=false;
	for(int v:G[u])if(v!=p)
	{
		dfs(v,u);
		if(now.size()<ret.size())
		{
			swap(now,ret);
			swap(nv,rv);
		}
		for(int x:ret)
		{
			if(now.find(x^rv^A[u]^nv)!=now.end())fn=true;
		}
		for(int x:ret)
		{
			now.insert(x^rv^nv);
		}
	}
	if(fn)
	{
		ans++;
		rv=0;
		ret.clear();
	}
	else
	{
		nv^=A[u];
		rv=nv;
		ret.swap(now);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=1;i<N;i++)
	{
		int x,y;cin>>x>>y;
		x--,y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(0,-1);
	cout<<ans<<endl;
}