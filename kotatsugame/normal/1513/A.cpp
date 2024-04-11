#include<cstdio>
#include<vector>
using namespace std;
int T,N,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		if(K*2+1>N)
		{
			puts("-1");
			continue;
		}
		int L=1,R=N;
		for(int i=0;i<N;i++)
		{
			if(i%2==0)printf("%d",L++);
			else
			{
				if(K-->0)printf("%d",R--);
				else printf("%d",L++);
			}
			putchar(i+1==N?10:32);
		}
	}
}