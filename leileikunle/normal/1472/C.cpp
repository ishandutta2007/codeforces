#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[200005],b[200005];
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i] = a[i];
		}
		for(int i=n;i>=1;i--)
		{	
			if(i+a[i]<=n) b[i] = b[i+a[i]] + a[i];
			else b[i] = a[i];
		}
		int maxn = 0;	
		for(int i=1;i<=n;i++)
		{
			maxn = max(maxn,b[i]);
		}
		cout<<maxn<<endl;
	}
 }