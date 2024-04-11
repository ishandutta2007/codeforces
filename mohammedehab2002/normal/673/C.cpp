#include <iostream>
#include <string.h>
using namespace std;
int ans[5005];
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	for (int i=0;i<n;i++)
	{
		int cnt[n+1],maxi=1,ind=arr[i];
		memset(cnt,0,sizeof(cnt));
		ans[arr[i]]++;
		cnt[arr[i]]=1;
		for (int x=i+1;x<n;x++)
		{
			cnt[arr[x]]++;
			if (cnt[arr[x]]>maxi)
			{
				maxi=cnt[arr[x]];
				ind=arr[x];
			}
			else if (cnt[arr[x]]==maxi)
			{
				if (arr[x]<=ind)
				{
					maxi=cnt[arr[x]];
					ind=arr[x];
				}
			}
			ans[ind]++;
		}
	}
	for (int i=1;i<=n;i++)
	cout << ans[i] << ' ';
}