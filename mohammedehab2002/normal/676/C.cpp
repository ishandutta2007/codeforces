#include <iostream>
using namespace std;
int cum[100005][2];
int main()
{
	int n,k;
	string s;
	cin >> n >> k >> s;
	for (int i=1;i<=n;i++)
	{
		cum[i][0]=cum[i-1][0]+(s[i-1]=='a');
		cum[i][1]=cum[i-1][1]+(s[i-1]=='b');
	}
	int ans=0;
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<2;x++)
		{
			int st=i,en=n;
			while (st!=en)
			{
				int mid=(st+en)/2;
				if (cum[mid+1][x]-cum[i][x]<=k)
				st=mid+1;
				else
				en=mid;
			}
			ans=max(ans,st-i);
		}
	}
	cout << ans;
}