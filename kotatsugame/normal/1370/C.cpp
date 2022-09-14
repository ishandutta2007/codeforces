#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		if(N%2==1)
		{
			puts(N==1?"FastestFinger":"Ashishgup");
		}
		else
		{
			int X=N;
			while(X%2==0)X/=2;
			if(N==2)
			{
				puts("Ashishgup");
			}
			else if(X==1)
			{
				puts("FastestFinger");
			}
			else if(N/X>=4)
			{
				puts("Ashishgup");
			}
			else
			{
				bool ok=false;
				for(int i=3;i*i<=X;i++)if(X%i==0)
				{
					ok=true;
					break;
				}
				puts(ok?"Ashishgup":"FastestFinger");
			}
		}
	}
}