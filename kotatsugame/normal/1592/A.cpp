#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,H;
int A[1010];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&H);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		sort(A,A+N);
		reverse(A,A+N);
		int m1=A[0],m2=A[1];
		int t=H/(m1+m2)*2;
		H%=m1+m2;
		printf("%d\n",H==0?t:H<=m1?t+1:t+2);
	}
}