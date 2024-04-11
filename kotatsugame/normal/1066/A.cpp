#include<cstdio>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int L,v,l,r;
		scanf("%d%d%d%d",&L,&v,&l,&r);
		int ans=L/v;
		ans-=r/v;
		ans+=(l-1)/v;
		printf("%d\n",ans);
	}
}