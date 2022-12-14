#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a[101] = {0};
		int n; cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int b[101] = {0};
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				b[abs(a[i] - a[j])] = 1;
			}
		}
		int sum = -1;
		for(int i=1;i<=101;i++)
		{
			if(b[i]) sum++;
		}
		cout<<sum<<endl;
	}
 }