#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=998244353;
long long power(long long a,long long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
int N,M;
int d[2<<17];
long long sd[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d",&d[i]);
	sort(d,d+N);
	for(int i=1;i<=N;i++)
	{
		sd[i]=sd[i-1]+d[i-1];
		sd[i]%=mod;
	}
	long long sum=sd[N];
	for(;M--;)
	{
		int a,b;scanf("%d%d",&a,&b);
		int L=-1,R=N;
		while(R-L>1)
		{
			int mid=L+R>>1;
			if(d[mid]>=b)R=mid;
			else L=mid;
		}
		int x=N-R;
		if(x<a)
		{
			printf("0\n");
		}
		else
		{
			printf("%lld\n",((x+1-a)*sd[R]%mod*power(x+1,mod-2)%mod+(x-a)*(sum-sd[R]+mod)%mod*power(x,mod-2)%mod)%mod);
		}
	}
}