#include<cstdio>
#include<algorithm>
using namespace std;
main()
{
	int A[3];
	for(int i=0;i<3;i++)scanf("%d",&A[i]);
	sort(A,A+3);
	int T=A[2]-A[1]-A[0];
	printf("%d\n",max(T+1,0));
}