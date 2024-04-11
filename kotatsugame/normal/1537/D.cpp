#include<cstdio>
using namespace std;
bool win[1<<17];
main()
{
	for(int N=1;N<=100;N++)
	{
		for(int i=2;i<N;i++)if(N%i==0&&!win[N-i])win[N]=true;
	}
	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		int N;
		scanf("%d",&N);
		int id=0;
		while(1<<id<N)id++;
		bool f;
		if(1<<id==N)
		{
			f=id>=2&&id%2==0;
		}
		else
		{
			if(N<=100)f=win[N];
			else f=N%2==0;
		}
		puts(f?"Alice":"Bob");
	}
}