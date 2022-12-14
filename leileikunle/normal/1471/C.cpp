#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[300005],c[300005];
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,m; cin>>n>>m;
		int maxn = 0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxn = max(maxn,a[i]);
		}
		for(int i=1;i<=m;i++)
		{
			cin>>c[i]; 
		}
		sort(a+1,a+n+1);
		sort(c+1,c+m+1);
		int j = 1; int sum = 0;
		for(int i=n;i>=1;i--)
		{
			if(a[i]>j&&j<=m)
			{
				sum += c[j];
				j++;
			}else if(a[i] == j &&j<=m)
			{
				if(c[j] >=c[a[i]]) sum+=c[a[i]];
				else{
					sum += c[j];
				j++;
				}
			}else{
				sum += c[a[i]];
			}
		}
		cout<<sum<<endl;
	}
 }