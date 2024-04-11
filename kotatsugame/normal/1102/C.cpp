#include<cstdio>
using namespace std;
int N,X,Y;
main()
{
	scanf("%d%d%d",&N,&X,&Y);
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		if(A<=X)cnt++;
	}
	printf("%d\n",X>Y?N:(cnt+1)/2);
}