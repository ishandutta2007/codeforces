#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,M;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		vector<vector<int> >G(N);
		for(int i=0;i<M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			G[u].push_back(v);
		}
		vector<int>vis(N,0);
		vector<int>S;
		for(int i=0;i<N;i++)
		{
			if(vis[i]==0)
			{
				for(int j:G[i])vis[j]|=1;
			}
			else if(vis[i]==1)
			{
				for(int j:G[i])vis[j]|=2;
			}
			else
			{
				S.push_back(i);
			}
		}
		sort(S.begin(),S.end());
		S.erase(unique(S.begin(),S.end()),S.end());
		printf("%d\n",(int)S.size());
		for(int i=0;i<S.size();i++)printf("%d%c",S[i]+1,i+1==S.size()?'\n':' ');
	}
}