#include<iostream>
#include<algorithm>
using namespace std;
int T,A[4];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		for(int i=0;i<4;i++)scanf("%d",&A[i]);
		sort(A,A+4);
		printf("%d\n",A[0]*A[2]);
	}
}