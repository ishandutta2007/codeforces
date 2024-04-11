#include<cstdio>
using namespace std;
const long long mod=998244353;
int N,M;
char A[2<<17],B[2<<17];
main()
{
	scanf("%d%d%s%s",&N,&M,A,B);
	int cnt=0;
	long long ans=0;
	if(N<M)
	{
		for(int i=N;i<M;i++)cnt+=B[M-i-1]-'0';
	}
	for(int i=0;i<N;i++)
	{
		ans=ans*2%mod;
		if(i+M>=N)cnt+=B[M-(N-i)]-'0';
		if(A[i]=='1')
		{
			ans=(ans+cnt)%mod;
		}
	}
	printf("%lld\n",ans);
}