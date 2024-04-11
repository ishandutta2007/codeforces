#include<cstdio>
using namespace std;
int N,K;
main()
{
	scanf("%d%d",&N,&K);
	if(K==1)
	{
		putchar('1');
		for(int i=1;i<N;i++)putchar('0');
		puts("");
		return 0;
	}
	int L=(N-K)/2+1;
	for(int i=0;i<N;i++)putchar(i%L==0?'1':'0');
	puts("");
}