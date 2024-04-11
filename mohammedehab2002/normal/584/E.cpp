#include <iostream>
#include <vector>
using namespace std;
int arr[2005],q[2005];
vector<pair<int,int> > v;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		q[a]=i;
	}
	int ans=0;
	while (1)
	{
		int cur=-1;
		for (int i=0;i<n;i++)
		{
			if (q[arr[i]]<i)
			{
				cur=i;
				break;
			}
		}
		if (cur==-1)
		break;
		for (int i=cur-1;i>=0;i--)
		{
			if (q[arr[i]]>i)
			{
				swap(arr[i],arr[cur]);
				ans+=cur-i;
				v.push_back({i+1,cur+1});
				cur=i;
				if (cur==q[arr[cur]])
				break;
			}
		}
	}
	printf("%d\n%d\n",ans,v.size());
	for (int i=0;i<v.size();i++)
	printf("%d %d\n",v[i].first,v[i].second);
}