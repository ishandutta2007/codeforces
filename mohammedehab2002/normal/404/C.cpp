#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int> > ans;
pair<int,int> d[100005];
int cnt[100005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	scanf("%d",&d[i].first),d[i].second=i;
	sort(d+1,d+n+1);
	if (d[1].first)
	{
		printf("-1");
		return 0;
	}
	int cur=1;
	for (int i=2;i<=n;i++)
	{
		if (!d[i].first)
		{
			printf("-1");
			return 0;
		}
		while (d[i].first-1>d[cur].first)
		cur++;
		if (d[i].first-1!=d[cur].first)
		{
			printf("-1");
			return 0;
		}
		if (cnt[cur]==k)
		cur++;
		if (d[i].first-1!=d[cur].first)
		{
			printf("-1");
			return 0;
		}
		cnt[cur]++;
		cnt[i]++;
		ans.push_back(make_pair(d[cur].second,d[i].second));
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
	printf("%d %d\n",ans[i].first,ans[i].second);
}