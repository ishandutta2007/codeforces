#include <iostream>
using namespace std;
pair<int,int> arr[105];
int main()
{
	int n,a,b,ans=0;
	cin >> n >> a >> b;
	for (int i=0;i<n;i++)
	cin >> arr[i].first >> arr[i].second;
	for (int i=0;i<n;i++)
	{
		for (int x=i+1;x<n;x++)
		{
			for (int m=0;m<4;m++)
			{
				if (m&1)
				swap(arr[i].first,arr[i].second);
				if (m&2)
				swap(arr[x].first,arr[x].second);
				bool ok=1;
				if (arr[i].first>a || arr[i].second>b || arr[x].first>a || arr[x].second>b)
				ok=0;
				if (arr[i].first>a-arr[x].first && arr[i].second>b-arr[x].second)
				ok=0;
				if (ok)
				ans=max(ans,arr[i].first*arr[i].second+arr[x].first*arr[x].second);
				if (m&1)
				swap(arr[i].first,arr[i].second);
				if (m&2)
				swap(arr[x].first,arr[x].second);
			}
		}
	}
	cout << ans;
}