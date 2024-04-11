#include<cstdio>
#include<vector>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		int pre=0;
		for(int i=0;i<N;i++)
		{
			int now=pre&~A[i];
			printf("%d%c",now,i+1==N?10:32);
			pre=A[i]^now;
		}
	}
}