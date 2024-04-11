#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int A[4];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		for(int i=0;i<4;i++)scanf("%d",&A[i]);
		sort(A,A+2);
		sort(A+2,A+4);
		if(A[0]>A[3]||A[2]>A[1])puts("NO");
		else puts("YES");
	}
}