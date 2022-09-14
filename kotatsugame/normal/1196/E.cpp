#include<cstdio>
using namespace std;
int T,B,W;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&B,&W);
		if(B==W)
		{
			puts("YES");
			for(int i=1;i<=B+W;i++)printf("1 %d\n",i);
		}
		else if(B>W)
		{
			int bm=W*3+1;
			if(bm<B)
			{
				puts("NO");
			}
			else
			{
				puts("YES");
				for(int i=1;i<=W*2+1;i++)printf("2 %d\n",i);
				B-=W+1;
				for(int i=1;i<=W;i++)
				{
					if(B>0)
					{
						B--;
						printf("1 %d\n",i*2);
					}
					if(B>0)
					{
						B--;
						printf("3 %d\n",i*2);
					}
				}
			}
		}
		else
		{
			int wm=B*3+1;
			if(wm<W)
			{
				puts("NO");
			}
			else
			{
				puts("YES");
				for(int i=2;i<=B*2+2;i++)printf("2 %d\n",i);
				W-=B+1;
				for(int i=1;i<=B;i++)
				{
					if(W>0)
					{
						W--;
						printf("1 %d\n",i*2+1);
					}
					if(W>0)
					{
						W--;
						printf("3 %d\n",i*2+1);
					}
				}
			}
		}
	}
}