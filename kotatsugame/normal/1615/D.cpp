#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,M;
vector<pair<int,int> >G[2<<17];
int A[2<<17],B[2<<17],V[2<<17];
bool vis[2<<17][2];
void dfs(int u,int p)
{
	vis[u][p]=true;
	for(pair<int,int>e:G[u])
	{
		int v=e.first;
		int np=p^e.second;
		if(!vis[v][np])dfs(v,np);
	}
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)
		{
			G[i].clear();
			vis[i][0]=vis[i][1]=false;
		}
		for(int i=0;i<N-1;i++)
		{
			cin>>A[i]>>B[i]>>V[i];
			A[i]--,B[i]--;
			if(V[i]>=0)
			{
				int f=__builtin_parity(V[i]);
				G[A[i]].push_back(make_pair(B[i],f));
				G[B[i]].push_back(make_pair(A[i],f));
			}
		}
		for(int i=0;i<M;i++)
		{
			int a,b,p;cin>>a>>b>>p;
			a--,b--;
			G[a].push_back(make_pair(b,p));
			G[b].push_back(make_pair(a,p));
		}
		for(int i=0;i<N;i++)if(!vis[i][0]&&!vis[i][1])
		{
			dfs(i,0);
		}
		bool out=false;
		for(int i=0;i<N;i++)if(vis[i][0]&&vis[i][1])out=true;
		if(out)cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			for(int i=0;i<N-1;i++)
			{
				cout<<A[i]+1<<" "<<B[i]+1<<" ";
				if(V[i]>=0)cout<<V[i]<<"\n";
				else cout<<(vis[A[i]][0]==vis[B[i]][0]?0:1)<<"\n";
			}
		}
	}
}