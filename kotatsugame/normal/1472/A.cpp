#include<cstdio>
using namespace std;
int T,W,H,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&W,&H,&N);
		long long X=1;
		while(W%2==0)W/=2,X*=2;
		while(H%2==0)H/=2,X*=2;
		puts(X<N?"NO":"YES");
	}
}