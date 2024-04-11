#include<cstdio>
#include<algorithm>
using namespace std;
int t;
main()
{
	scanf("%d",&t);
	for(;t--;)
	{
		int N,P,A;scanf("%d%d",&N,&P);
		int L,R=-1;
		for(int i=1;i<N;i++)
		{
			scanf("%d",&A);
			if(abs(A-P)>=2)
			{
				L=i;
				R=i+1;
			}
			P=A;
		}
		if(R<0)puts("NO");
		else
		{
			puts("YES");
			printf("%d %d\n",L,R);
		}
	}
}