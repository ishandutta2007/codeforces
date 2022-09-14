#include<cstdio>
using namespace std;
int T,N,S;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&S);
		N=N/2+1;
		printf("%d\n",S/N);
	}
}