#include<cstdio>
using namespace std;
int N;
const long long mod=998244353;
int ans[2<<17];
main()
{
	scanf("%d",&N);
	ans[N-1]=10;
	long long p=1;
	for(long long i=N-2;i>=0;i--)
	{
		ans[i]=(int)((81*(N-i-1)+99)*p%mod);
		p=p*10%mod;
	}
	for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?'\n':' ');
}