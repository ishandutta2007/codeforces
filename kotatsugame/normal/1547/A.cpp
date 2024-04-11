#include<cstdio>
#include<algorithm>
using namespace std;
int T,A,B,C,D,E,F;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d%d%d%d",&A,&B,&C,&D,&E,&F);
		int ans=abs(A-C)+abs(B-D);
		if(A==C)
		{
			if(A==E&&min(B,D)<F&&F<max(B,D))ans+=2;
		}
		if(B==D)
		{
			if(B==F&&min(A,C)<E&&E<max(A,C))ans+=2;
		}
		printf("%d\n",ans);
	}
}