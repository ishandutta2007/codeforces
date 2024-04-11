#include <iostream>
#include <vector>
using namespace std;
int cnt[1000005],dp[1000005],arr[1000005];
vector<int> v;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		arr[i]=a;
		if (a<=m)
		cnt[a]++;
	}
	for (int i=1;i<=m;i++)
	{
		for (int x=i;x<=m;x+=i)
		dp[x]+=cnt[i];
	}
	int best=1;
	for (int i=2;i<=m;i++)
	{
		if (dp[i]>dp[best])
		best=i;
	}
	for (int i=0;i<n;i++)
	{
		if (best%arr[i]==0)
		v.push_back(i+1);
	}
	printf("%d %d\n",best,v.size());
	for (int i=0;i<v.size();i++)
	printf("%d ",v[i]);
}