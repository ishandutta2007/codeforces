#include<cstdio>
#include<algorithm>
using namespace std;
int N,K;
int A[5000];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	double ans=0;
	for(int i=0;i<N;i++)
	{
		int now=0;
		for(int j=i;j<N;j++)
		{
			now+=A[j];
			if(j-i+1>=K)
			{
				ans=max(ans,now/(double)(j-i+1));
			}
		}
	}
	printf("%.16f\n",ans);
}