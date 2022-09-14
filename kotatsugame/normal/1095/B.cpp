#include<iostream>
#include<algorithm>
using namespace std;
int N,A[1<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	printf("%d\n",min(A[N-1]-A[1],A[N-2]-A[0]));
}