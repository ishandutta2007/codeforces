#include<iostream>
#include<vector>
using namespace std;
int N,K;
vector<int>G[2<<17];
int now;
int dfs(int u,int m)
{
	int mx=0;
	for(int v:G[u])
	{
		int to=dfs(v,m)+1;
		if(u==0)
		{
			if(to>m)now++;
			else mx=max(mx,to);
		}
		else
		{
			if(to>=m)now++;
			else mx=max(mx,to);
		}
	}
	return mx;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int p;cin>>p;
			G[p-1].push_back(i);
		}
		int L=0,R=N-1;
		while(R-L>1)
		{
			int mid=(L+R)/2;
			now=0;
			dfs(0,mid);
			if(now<=K)R=mid;
			else L=mid;
		}
		cout<<R<<"\n";
	}
}