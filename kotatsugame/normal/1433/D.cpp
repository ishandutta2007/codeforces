#include<cstdio>
using namespace std;
int T,N;
int A[5050];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int id=-1;
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&A[i]);
			if(id<0&&A[i]!=A[1])id=i;
		}
		if(id<0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=2;i<=N;i++)
		{
			if(A[i]!=A[1])printf("1 %d\n",i);
			else printf("%d %d\n",id,i);
		}
	}
}