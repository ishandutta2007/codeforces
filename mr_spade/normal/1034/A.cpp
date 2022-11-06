#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
using std::__gcd;
using std::vector;
using std::bitset;
const int N=2e7+5;
vector<int> prime;
bitset<N> isprime;
inline void sieve(int n)
{
	register int i;
	isprime.set();isprime[1]=0;
	for(i=1;i<=n;i++)
	{
		if(isprime[i])
			prime.emplace_back(i);
		for(auto j:prime)
		{
			if(i*j>n)
				break;
			isprime[i*j]=0;
			if(i%j==0)
				break;
		}
	}
	return;
}
int n,ans;
int p[300005];
int a[N];
signed main()
{
	int res,g=0;
	register int i;
	sieve(15000000);
	scanf("%d",&n);ans=n;
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]),g=__gcd(g,p[i]);
	for(i=1;i<=n;i++)
		a[p[i]/g]++;
	for(auto x:prime)
	{
		res=0;
		for(i=x;i<=15000000;i+=x)
			res+=a[i];
		if(n-res<ans)
			ans=n-res;
	}
	if(ans==n)
		puts("-1");
	else
		printf("%d\n",ans);
	return 0;
}