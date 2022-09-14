#include<cstdio>
#include<algorithm>
using namespace std;
int N;
long long cumsum[1<<20];
const int buf=2<<17;
main()
{
	scanf("%d",&N);
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		int b;scanf("%d",&b);
		ans=max(ans,cumsum[buf+b-i]+=b);
	}
	printf("%lld\n",ans);
}