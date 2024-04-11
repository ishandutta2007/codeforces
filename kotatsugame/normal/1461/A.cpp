#include<cstdio>
using namespace std;
int T,N,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)printf("%c",i%3==0?'a':i%3==1?'b':'c');
		puts("");
	}
}