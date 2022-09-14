#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,u,v;
int A[111];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&u,&v);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
		}
		int ans=2e9;
		ans++;
		for(int i=0;i<N-1;i++)
		{
			if(abs(A[i]-A[i+1])>=2)
			{
				ans=0;
			}
			else if(abs(A[i]-A[i+1])==1)
			{
				ans=min(ans,min(u,v));
			}
			else
			{
				ans=min(ans,v+min(u,v));
			}
		}
		printf("%d\n",ans);
	}
}