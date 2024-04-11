#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int N,M;
vector<int>G[2<<17];
int U[2<<17],V[2<<17];
int col[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d%d",&U[i],&V[i]);
		U[i]--,V[i]--;
		G[U[i]].push_back(V[i]);
		G[V[i]].push_back(U[i]);
	}
	col[0]=1;
	queue<int>P;
	P.push(0);
	while(!P.empty())
	{
		int u=P.front();P.pop();
		for(int v:G[u])
		{
			if(col[v]==0)
			{
				col[v]=3-col[u];
				P.push(v);
			}
			else if(col[v]==col[u])
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	for(int i=0;i<M;i++)putchar(col[U[i]]==1?'0':'1');
	puts("");
}