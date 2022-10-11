#include <iostream>
using namespace std;
int main()
{
	int n,i,x,j,ans=0;
	cin >> n;
	pair <int,int> arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i].first >> arr[i].second;
	if (n>2)
	{
		for (i=0;i<n;i++)
		{
			for (x=i;x<n;x++)
			{
				for (j=x;j<n;j++)
				{
					if ((arr[x].first-arr[j].first)*(arr[i].second-arr[x].second)!=(arr[i].first-arr[x].first)*(arr[x].second-arr[j].second))
					ans++;
				}
			}
		}
	}
	cout << ans;
}