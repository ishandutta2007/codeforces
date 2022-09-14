#include<cstdio>
#include<algorithm>
using namespace std;
int T,A,B,X,Y,N;
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d%d%d%d%d",&A,&B,&X,&Y,&N);
		printf("%lld\n",min(
			(long long)max(A-N,X)*max(B-max(N-(A-X),0),Y),
			(long long)max(B-N,Y)*max(A-max(N-(B-Y),0),X)
		));
    }
}