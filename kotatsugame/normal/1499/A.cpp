#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int N,X,Y,a,b;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d%d%d",&N,&X,&Y,&a,&b);
		if(X<Y)swap(X,Y);
		int c=Y+(X-Y)/2;
		int d=N-X+(X-Y)/2;
		puts(a<=c&&b<=d?"YES":"NO");
	}
}