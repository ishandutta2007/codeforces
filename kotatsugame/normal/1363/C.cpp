#include<cstdio>
#include<vector>
using namespace std;
int T,N,X;
vector<int>G[1010];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&X);
		X--;
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(G[X].size()<=1)puts("Ayush");
		else puts((N-3)%2==0?"Ashish":"Ayush");
	}
}