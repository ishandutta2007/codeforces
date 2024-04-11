#include<cstdio>
using namespace std;
int N,A[101];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int ans=0;
	for(int i=2;i<N;i++)
	{
		if(A[i-2]==1&&A[i-1]==0&&A[i]==1)
		{
			ans++;
			A[i]=0;
		}
	}
	printf("%d\n",ans);
}