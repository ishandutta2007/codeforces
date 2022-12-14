#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int  t; cin>>t;
	while(t--)
	{
		int m; cin>>m;
		int a[m+1]={0};
		for(int i=1;i<=m;i++) cin>>a[i];
		int n ;cin>>n;
		int b[n+1] = {0};
		for(int i=1;i<=n;i++) cin>>b[i];
		int sum = 0;
		int sum1 = 0;
		for(int i=1;i<=m;i++)
		{
			sum1 += a[i];
			sum = max(sum,sum1);
		}
		int sum2 = 0, sum3 = 0;
		for(int i=1;i<=n;i++)
		{
			sum3 += b[i];
			sum2 = max(sum2,sum3);
		}
		cout<<sum2+sum<<endl;
		
		

		
}}