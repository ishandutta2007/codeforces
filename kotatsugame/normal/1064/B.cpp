#include<cstdio>
using namespace std;
main()
{
	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		int N;
		scanf("%d",&N);
		printf("%d\n",1<<__builtin_popcount(N));
	}
}