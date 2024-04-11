#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)printf("%d%c",1,i==N-1?'\n':' ');
	}
}