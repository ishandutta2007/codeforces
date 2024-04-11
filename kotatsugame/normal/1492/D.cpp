#include<cstdio>
using namespace std;
int A,B,K;
main()
{
	scanf("%d%d%d",&A,&B,&K);
	if(K==0)
	{
		puts("Yes");
		for(int i=0;i<B;i++)putchar('1');for(int i=0;i<A;i++)putchar('0');puts("");
		for(int i=0;i<B;i++)putchar('1');for(int i=0;i<A;i++)putchar('0');puts("");
	}
	else if(A==0||B==1)
	{
		puts("No");
	}
	else
	{
		if(K<=A)
		{
			puts("Yes");
			for(int i=0;i<B;i++)putchar('1');for(int i=0;i<A;i++)putchar('0');puts("");
			for(int i=0;i<B-1;i++)putchar('1');
			for(int i=0;i<K;i++)putchar('0');
			putchar('1');
			for(int i=K;i<A;i++)putchar('0');
			puts("");
		}
		else if(K<=A+B-2)
		{
			puts("Yes");
			K-=A;
			int id=B-1-K;
			for(int i=0;i<B;i++)putchar('1');for(int i=0;i<A;i++)putchar('0');puts("");
			for(int i=0;i<id;i++)putchar('1');
			putchar('0');
			for(int i=id+1;i<B;i++)putchar('1');
			for(int i=1;i<A;i++)putchar('0');
			putchar('1');
			puts("");
		}
		else
		{
			puts("No");
		}
	}
}