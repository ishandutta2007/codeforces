#include<cstdio>
using namespace std;
int N,M;
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			int a;
			scanf("%d",&a);
			if((i+j)%2==0)
			{
				printf("720720");
			}
			else
			{
				printf("%d",720720-a*a*a*a);
			}
			printf("%c",j+1==M?10:32);
		}
	}
}