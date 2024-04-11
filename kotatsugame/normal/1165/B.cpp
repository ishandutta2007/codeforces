#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int A[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	int now=0;
	for(int i=0;i<N;i++)
	{
		if(now<A[i])now++;
	}
	printf("%d\n",now);
}