#include <iostream>
#include <map>
#include <set>
using namespace std;
map<long long,int> dp[61];
int solve(int x,long long mask)
{
	if (dp[x].count(mask))
	return dp[x][mask];
	set<int> s;
	for (int i=0;i<x;i++)
	{
		if (mask&(1LL<<i))
		s.insert(solve(x-i-1,(mask^(1LL<<i))));
	}
	if (s.size()==0)
	return 0;
	int l,ans=-1;
	for (auto it=s.begin();it!=s.end();l=*it,it++)
	{
		if (it==s.begin())
		continue;
		if (*it!=l+1)
		{
			ans=l+1;
			break;
		}
	}
	if ((*s.begin())!=0)
	ans=0;
	if (ans==-1)
	{
		auto it=s.end();
		it--;
		ans=*it+1;
	}
	return dp[x][mask]=ans;
}
int main()
{
	for (int i=1;i<=60;i++)
	solve(i,(1LL<<60)-1);
	int n,gr=0;
	scanf("%d",&n);
	while (n--)
	{
		int m;
		scanf("%d",&m);
		gr^=dp[m][(1LL<<60)-1];
	}
	if (gr)
	printf("NO");
	else
	printf("YES");
}