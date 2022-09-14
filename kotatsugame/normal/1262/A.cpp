#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int L=1e9+1,R=0;
		for(;N--;)
		{
			int l,r;scanf("%d%d",&l,&r);
			if(L>r)L=r;
			if(R<l)R=l;
		}
		printf("%d\n",R<L?0:R-L);
	}
}