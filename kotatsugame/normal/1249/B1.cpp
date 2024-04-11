#include<cstdio>
using namespace std;
int T,N,P[2<<17];
bool vis[2<<17];
int ans[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&P[i]);
			P[i]--;
			vis[i]=false;
		}
		for(int i=0;i<N;i++)if(!vis[i])
		{
			int cnt=0,u=i;
			while(!vis[u])
			{
				cnt++;
				vis[u]=true;
				u=P[u];
			}
			do{
				ans[u]=cnt;
				u=P[u];
			}while(u!=i);
		}
		for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?10:32);
	}
}