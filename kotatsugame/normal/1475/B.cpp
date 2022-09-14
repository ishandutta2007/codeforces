#include<cstdio>
using namespace std;
int T;
int N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int c=N/2020;
		N%=2020;
		puts(0<=N&&N<=c?"YES":"NO");
	}
}