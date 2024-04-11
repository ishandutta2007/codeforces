#include<cstdio>
using namespace std;
int Q;
int A[3<<17],C[3<<17];
int pr[19][3<<17];
bool vis[3<<17];
main()
{
	scanf("%d%d%d",&Q,&A[0],&C[0]);
	for(int k=0;k<19;k++)pr[k][0]=-1;
	for(int i=1;i<=Q;i++)
	{
		int t;scanf("%d",&t);
		if(t==1)
		{
			int p;
			scanf("%d%d%d",&p,&A[i],&C[i]);
			for(int k=0;k<19;k++)
			{
				pr[k][i]=p;
				if(p>=0)p=pr[k][p];
			}
		}
		else
		{
			int v,w;scanf("%d%d",&v,&w);
			int L=0;
			{
				int u=v;
				for(int k=19;k--;)
				{
					if(pr[k][u]>=0&&!vis[pr[k][u]])
					{
						L+=1<<k;
						u=pr[k][u];
					}
				}
			}
			int sw=0;
			long long sm=0;
			while(L>=0&&w>0)
			{
				int u=v;
				for(int k=0;k<19;k++)if(L>>k&1)u=pr[k][u];
				int now=A[u]<w?A[u]:w;
				sw+=now;
				sm+=(long long)now*C[u];
				w-=now;
				A[u]-=now;
				if(A[u]==0)vis[u]=true;
				L--;
			}
			printf("%d %lld\n",sw,sm);
		}
		fflush(stdout);
	}
}