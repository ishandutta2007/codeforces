#include<cstdio>
using namespace std;
int T,N,M,A,B;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d%d",&N,&M,&A,&B);
		if(N*A!=M*B)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			for(int i=0;i<N;i++)
			{
				int t=i*A%M;
				int l1=t,r1=t+A,l2=0,r2=0;
				if(r1>M)
				{
					r2=r1-M;
					r1=M;
				}
				for(int j=0;j<M;j++)
				{
					if(l1<=j&&j<r1||l2<=j&&j<r2)putchar('1');
					else putchar('0');
				}
				puts("");
			}
		}
	}
}