#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			if(i==0)printf("9");
			else
			{
				printf("%d",(7+i)%10);
			}
		}
		puts("");
	}
}