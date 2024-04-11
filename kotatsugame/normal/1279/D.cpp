#include<cstdio>
#include<vector>
using namespace std;
long long mod=998244353;
long long inv[1<<20];
int N;
int k[1<<20];
vector<int>A[1<<20];
int cnt[1<<20];
main()
{
	scanf("%d",&N);
	inv[1]=1;
	for(long long i=2;i<1<<20;i++)
	{
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++)
		{
			int a;scanf("%d",&a);
			A[i].push_back(a);
			cnt[a]++;
		}
	}
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		long long now=0;
		for(int j=0;j<k[i];j++)
		{
			now+=cnt[A[i][j]]*inv[N];
			now%=mod;
		}
		now=now*inv[k[i]]%mod;
		ans=(ans+now)%mod;
	}
	printf("%lld\n",ans*inv[N]%mod);
}