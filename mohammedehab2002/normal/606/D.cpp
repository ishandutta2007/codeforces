#include <iostream>
#include <algorithm>
using namespace std;
pair<pair<int,int>,int> arr[100005];
pair<int,int> ans[100005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&arr[i].first.first,&arr[i].first.second);
		arr[i].first.second^=1;
		arr[i].second=i;
	}
	sort(arr,arr+m);
	int cur=1,cur2=1,cur3=3;
	for (int i=0;i<m;i++)
	{
		if (!arr[i].first.second)
		{
			ans[arr[i].second]={cur++,cur};
			continue;
		}
		if (cur3>cur)
		{
			printf("-1");
			return 0;
		}
		ans[arr[i].second]={cur2,cur3};
		cur2++;
		if (cur2+1==cur3)
		{
			cur2=1;
			cur3++;
		}
	}
	for (int i=0;i<m;i++)
	printf("%d %d\n",ans[i].first,ans[i].second);
}