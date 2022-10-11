#include <iostream>
#include <set>
using namespace std;
int arr[100005];
long long dp[100005],cum[100005];
multiset<int> s;
int main()
{
	int n,c;
	scanf("%d%d",&n,&c);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	for (int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+arr[i];
		cum[i]=cum[i-1]+arr[i];
		s.insert(arr[i]);
		if (i-c>=0)
		{
			if (i!=c)
			s.erase(s.find(arr[i-c]));
			dp[i]=min(dp[i],dp[i-c]+cum[i]-cum[i-c]-*s.begin());
		}
	}
	printf("%I64d",dp[n]);
}