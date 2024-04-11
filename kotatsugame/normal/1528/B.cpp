#include<cstdio>
using namespace std;
const int mod=998244353;
int f[1<<20];
int N;
main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)for(int j=i;j<=N;j+=i)f[j]++;
	int sum=0;
	for(int i=1;i<=N;i++)
	{
		f[i]=(f[i]+sum)%mod;
		sum=(sum+f[i])%mod;
	}
	printf("%d\n",f[N]);
}