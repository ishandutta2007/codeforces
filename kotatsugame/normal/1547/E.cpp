#include<cstdio>
#include<queue>
using namespace std;
int T,N;
int A[3<<17];
int D[3<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int K;
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)D[i]=2e9;
		for(int i=0;i<K;i++)scanf("%d",&A[i]);
		priority_queue<pair<int,int> >P;
		for(int i=0;i<K;i++)
		{
			int t;
			scanf("%d",&t);
			int u=A[i]-1;
			if(D[u]>t)
			{
				D[u]=t;
				P.push(make_pair(-t,u));
			}
		}
		while(!P.empty())
		{
			int u=P.top().second;
			int t=-P.top().first;
			P.pop();
			if(D[u]<t)continue;
			for(int d=-1;d<=1;d+=2)
			{
				int v=u+d;
				if(v>=0&&v<N&&D[v]>t+1)
				{
					D[v]=t+1;
					P.push(make_pair(-D[v],v));
				}
			}
		}
		for(int i=0;i<N;i++)
		{
			printf("%d%c",D[i],i+1==N?10:32);
		}
	}
}