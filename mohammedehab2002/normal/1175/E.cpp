#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MX 500000
int dp[20][MX+5],cnt[MX+5];
vector<int> v[MX+5];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (n--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		v[l].push_back(r);
		cnt[r]++;
	}
	multiset<int> s;
	for (int i=MX;i>=0;i--)
	{
		while (cnt[i]--)
		s.insert(i);
		if (s.empty() || *prev(s.end())==i)
		dp[0][i]=-1;
		else
		dp[0][i]=*prev(s.end());
		for (int j=1;j<20;j++)
		{
			dp[j][i]=-1;
			if (dp[j-1][i]!=-1)
			dp[j][i]=dp[j-1][dp[j-1][i]];
		}
		for (int j:v[i])
		s.erase(s.find(j));
	}
	while (m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int cur=l,ans=0;
		for (int i=19;i>=0;i--)
		{
			if (dp[i][cur]!=-1 && dp[i][cur]<r)
			{
				cur=dp[i][cur];
				ans+=(1<<i);
			}
		}
		if (dp[0][cur]>=r)
		printf("%d\n",ans+1);
		else
		printf("-1\n");
	}
}