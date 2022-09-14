#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int N;
map<long long,int>M;
main()
{
	scanf("%d",&N);
	long long cumsum=0;
	M[0LL]=0;
	long long ans=0;
	int cumi=0;
	for(int i=1;i<=N;i++)
	{
		int A;scanf("%d",&A);
		cumsum+=A;
		if(M.find(cumsum)!=M.end())cumi=max(cumi,M[cumsum]+1);
		ans+=i-cumi;
		M[cumsum]=i;
	}
	printf("%lld\n",ans);
}