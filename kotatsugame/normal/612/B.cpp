#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int id[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int f;scanf("%d",&f);
		id[f-1]=i;
	}
	long long ans=0;
	for(int i=1;i<N;i++)ans+=abs(id[i]-id[i-1]);
	printf("%lld\n",ans);
}