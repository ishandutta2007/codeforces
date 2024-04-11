#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > ans;
int arr[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	vector<int> cur;
	for (int i=0;i<n;i++)
	{
		cur.push_back(arr[i]);
		if (!arr[i])
		{
			ans.push_back(cur);
			cur.clear();
		}
	}
	if (arr[n-1]==1 || (ans.size()==2 && arr[n-2]==0))
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	if (ans.size()<3)
	{
		for (int i=0;i<n-1;i++)
		printf("%d->",arr[i]);
		printf("0");
		return 0;
	}
	for (int i=0;i<ans.size();i++)
	{
		if (i==ans.size()-3)
		printf("(");
		printf("(");
		for (int x=0;x<ans[i].size();x++)
		{
			printf("%d",ans[i][x]);
			if (x!=ans[i].size()-1)
			printf("->");
		}
		printf(")");
		if (i==ans.size()-2)
		printf(")");
		if (i!=ans.size()-1)
		printf("->");
	}
}