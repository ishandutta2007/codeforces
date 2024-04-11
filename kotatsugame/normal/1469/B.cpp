#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int f()
{
	int N;scanf("%d",&N);
	int ret=0,now=0;
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);
		now=max(now,ret+=A);
	}
	return now;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int N=f();
		int M=f();
		printf("%d\n",N+M);
	}
}