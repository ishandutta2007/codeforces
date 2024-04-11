#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int T,N,M;
int C[3<<17],k[3<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&k[i]);
			k[i]--;
		}
		for(int i=0;i<M;i++)scanf("%d",&C[i]);
		long long ans=0;
		for(int i=0;i<N;i++)ans+=C[k[i]];
		priority_queue<int>P;
		int id=0;
		sort(k,k+N);
		for(int i=0;i<N;i++)
		{
			int L=P.empty()?2e9:-P.top();
			int R=id<M?C[id]:2e9;
			if(L<R)
			{
				if(L<C[k[i]])
				{
					P.pop();
					P.push(-C[k[i]]);
					ans-=C[k[i]]-L;
				}
			}
			else
			{
				if(R<C[k[i]])
				{
					ans-=C[k[i]]-R;
					P.push(-C[k[i]]);
					id++;
				}
			}
		}
		printf("%lld\n",ans);
	}
}