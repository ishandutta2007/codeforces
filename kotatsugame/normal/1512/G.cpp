#include<cstdio>
using namespace std;
int T,C;
const int LIM=1e7;
long long sum[LIM+1];
int F[LIM+1];
main()
{
	for(int i=1;i<=LIM;i++)for(int j=i;j<=LIM;j+=i)sum[j]+=i;
	for(int i=1;i<=LIM;i++)if(sum[i]<=LIM&&F[sum[i]]==0)F[sum[i]]=i;
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&C);
		printf("%d\n",F[C]==0?-1:F[C]);
	}
}