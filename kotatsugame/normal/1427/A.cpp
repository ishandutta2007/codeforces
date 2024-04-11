#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int sum=0;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			sum+=A[i];
		}
		if(sum==0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		sort(A,A+N);
		if(sum>0)reverse(A,A+N);
		for(int i=0;i<N;i++)printf("%d%c",A[i],i+1==N?'\n':' ');
	}
}