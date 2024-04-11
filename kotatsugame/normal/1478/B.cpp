#include<cstdio>
using namespace std;
int T,Q,D;
bool dp[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&Q,&D);
		for(int i=0;i<100;i++)dp[i]=false;
		dp[0]=true;
		for(int j=0;j<D;j++)
		{
			int t=j*10+D;
			for(int k=0;k+t<100;k++)if(dp[k])dp[k+t]=true;
		}
		for(;Q--;)
		{
			int A;
			scanf("%d",&A);
			if(A>=10*D)puts("YES");
			else puts(dp[A]?"YES":"NO");
		}
	}
}