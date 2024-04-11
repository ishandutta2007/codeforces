#include<cstdio>
using namespace std;
int T,N,M,X,L,R,l,r;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&X,&M);
		L=X;R=X;
		for(;M--;)
		{
			scanf("%d%d",&l,&r);
			if(l<=L&&L<=r)L=l;
			if(l<=R&&R<=r)R=r;
		}
		printf("%d\n",R-L+1);
	}
}