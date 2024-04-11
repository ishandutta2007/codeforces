#include<cstdio>
#include<algorithm>
using namespace std;
int N,A[151515];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	int prv=0;
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		if(prv<A[i]-1)
		{
			prv=A[i]-1;
			cnt++;
		}
		else if(prv<A[i])
		{
			prv=A[i];
			cnt++;
		}
		else if(prv<A[i]+1)
		{
			prv=A[i]+1;
			cnt++;
		}
	}
	printf("%d\n",cnt);
}