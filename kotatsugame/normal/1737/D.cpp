#include<iostream>
using namespace std;
int N,M;
int G[500][500];
int U[250000],V[250000],W[250000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)
		{
			if(i==j)G[i][j]=0;
			else G[i][j]=1e9;
		}
		for(int i=0;i<M;i++)
		{
			cin>>U[i]>>V[i]>>W[i];
			U[i]--,V[i]--;
			G[U[i]][V[i]]=G[V[i]][U[i]]=1;
		}
		for(int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++)
		{
			G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
		}
		long long ans=9e18;
		for(int i=0;i<M;i++)
		{
			int w=min(G[0][U[i]]+G[N-1][V[i]],G[0][V[i]]+G[N-1][U[i]]);
			for(int k=0;k<N;k++)
			{
				w=min(w,G[0][k]+G[N-1][k]+min(G[U[i]][k],G[V[i]][k])+1);
			}
			ans=min(ans,(long long)W[i]*(w+1));
		}
		cout<<ans<<"\n";
	}
}