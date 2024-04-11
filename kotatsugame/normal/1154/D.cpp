#include<cstdio>
using namespace std;
int N,B,A;
main()
{
	scanf("%d%d%d",&N,&B,&A);
	int b=B,a=A;
	for(int i=0;i<N;i++)
	{
		int S;
		scanf("%d",&S);
		if(a==A)a--;
		else if(S==1)
		{
			if(b>0)
			{
				b--;
				a++;
			}
			else if(a>0)a--;
			else
			{
				printf("%d\n",i);
				return 0;
			}
		}
		else
		{
			if(a>0)
			{
				a--;
			}
			else if(b>0)b--;
			else
			{
				printf("%d\n",i);
				return 0;
			}
		}
	}
	printf("%d\n",N);
}