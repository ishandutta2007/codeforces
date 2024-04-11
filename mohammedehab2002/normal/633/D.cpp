#include <iostream>
#include <map>
using namespace std;
map<int,int> m;
int arr[1005];
int go(int a,int b)
{
	int ans=0;
	if (m[a+b])
	{
		m[a+b]--;
		ans=go(b,a+b)+1;
		m[a+b]++;
	}
	return ans;
}
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		m[arr[i]]++;
	}
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n;x++)
		{
			if (i==x)
			continue;
			if (!arr[i] && !arr[x])
			ans=max(ans,m[0]);
			else
			{
				m[arr[i]]--;
				m[arr[x]]--;
				ans=max(ans,go(arr[i],arr[x])+2);
				m[arr[i]]++;
				m[arr[x]]++;
			}
		}
	}
	printf("%d",ans);
}