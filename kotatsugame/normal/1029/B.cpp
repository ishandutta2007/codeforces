#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int A[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int ans=0;
	int now=0;
	for(int i=0;i<N;i++)
	{
		if(i>0&&A[i-1]*2<A[i])now=0;
		now++;
		ans=max(ans,now);
	}
	printf("%d\n",ans);
}