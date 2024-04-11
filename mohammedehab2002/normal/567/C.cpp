#include <iostream>
#include <set>
#include <map>
using namespace std;
map<int,long long> dp[4];
set<int> s;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		if (a%k==0)
		{
			dp[3][a]+=dp[2][a/k];
			dp[2][a]+=dp[1][a/k];
		}
		dp[1][a]++;
		s.insert(a);
	}
	long long ans=0;
	for (set<int>::iterator it=s.begin();it!=s.end();it++)
	ans+=dp[3][*it];
	printf("%I64d",ans);
}