#include<cstdio>
using namespace std;
int Q;
char S[1<<17];
main()
{
	scanf("%d",&Q);
	for(;Q--;)
	{
		scanf("%s",S);
		int L=0,R=0,U=0,D=0;
		for(int i=0;S[i];i++)
		{
			if(S[i]=='L')L++;
			else if(S[i]=='R')R++;
			else if(S[i]=='U')U++;
			else D++;
		}
		int X=L<R?L:R,Y=U<D?U:D;
		if(X&&Y)
		{
			printf("%d\n",X+X+Y+Y);
			for(int i=0;i<X;i++)putchar('L');
			for(int i=0;i<Y;i++)putchar('U');
			for(int i=0;i<X;i++)putchar('R');
			for(int i=0;i<Y;i++)putchar('D');
			puts("");
		}
		else if(X)
		{
			printf("2\nLR\n");
		}
		else if(Y)
		{
			printf("2\nUD\n");
		}
		else
		{
			printf("0\n\n");
		}
	}
}