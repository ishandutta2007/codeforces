#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=998244353;
int N;
long long A[2<<17];
int B[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%lld",&A[i]),A[i]*=i+1,A[i]*=N-i;
	for(int i=0;i<N;i++)scanf("%d",&B[i]);
	sort(A,A+N);
	sort(B,B+N);
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		ans+=A[i]%mod*B[N-i-1];
		ans%=mod;
	}
	printf("%d\n",(int)ans);
}