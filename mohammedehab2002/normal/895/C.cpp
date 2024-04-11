#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define mod 1000000007
int dp[75][(1<<19)],pow[100005];
vector<int> primes;
int cnt[75];
set<int> s;
int main()
{
	pow[0]=1;
	for (int i=1;i<100005;i++)
	pow[i]=(pow[i-1]*2)%mod;
	for (int i=2;i<=70;i++)
	{
		bool prime=1;
		for (int x=2;x*x<=i;x++)
		{
			if (i%x==0)
			prime=0;
		}
		if (prime)
		primes.push_back(i);
	}
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		s.insert(a);
		cnt[a]++;
	}
	dp[0][0]=1;
	int ind=1;
	for (set<int>::iterator it=s.begin();it!=s.end();it++,ind++)
	{
		int mask=0;
		for (int x=0;x<primes.size();x++)
		{
			int tmp=*it,ans=0;
			while (tmp%primes[x]==0)
			tmp/=primes[x],ans++;
			if (ans%2)
			mask|=(1<<x);
		}
		for (int m=0;m<(1<<19);m++)
		{
			long long tmp=dp[ind-1][m]+dp[ind-1][(m^mask)];
			tmp=(tmp*pow[cnt[*it]-1])%mod;
			dp[ind][m]=tmp;
		}
	}
	printf("%d",dp[s.size()][0]-1);
}