#include<iostream>
using namespace std;
int T;
int C[3],A[5];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		for(int i=0;i<3;i++)scanf("%d",&C[i]);
		for(int i=0;i<5;i++)scanf("%d",&A[i]);
		C[0]-=A[0];
		C[1]-=A[1];
		C[2]-=A[2];
		if(C[0]>=0)A[3]-=C[0];
		else
		{
			puts("NO");
			continue;
		}
		if(C[1]>=0)A[4]-=C[1];
		else
		{
			puts("NO");
			continue;
		}
		int rest=(A[3]>0?A[3]:0)+(A[4]>0?A[4]:0);
		puts(rest<=C[2]?"YES":"NO");
	}
}