#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int T,N;
int A[2][4<<17];
int id[4<<17][2];
bool vis[4<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)vis[i]=false;
		for(int j=0;j<2;j++)for(int i=0;i<N;i++)
		{
			scanf("%d",&A[j][i]);
			A[j][i]--;
			id[A[j][i]][j]=i;
		}
		int ans=1;
		for(int i=0;i<N;i++)if(!vis[i])
		{
			ans=ans*2%1000000007;
			queue<int>P;
			P.push(i);
			vis[i]=true;
			while(!P.empty())
			{
				int u=P.front();P.pop();
				for(int k=0;k<2;k++)
				{
					int v=id[A[k][u]][!k];
					if(!vis[v])
					{
						vis[v]=true;
						P.push(v);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}