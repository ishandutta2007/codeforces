#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[300005];
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int tot = 0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=2;i<n;i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1] || a[i]<a[i-1]&&a[i]<a[i+1])
				tot++;
		}
		a[0] = a[1];
		a[n+1] = a[n];
		int minn = tot;
		for(int i=2;i<n;i++)
		{
			int b = 0,c = 0,d = 0;
			if((a[i-1]>a[i-2]&&a[i-1]>a[i]) || (a[i-1]<a[i-2]&&a[i-1]<a[i])) b++;
			if((a[i]>a[i-1]&&a[i]>a[i+1]) || (a[i]<a[i-1]&&a[i]<a[i+1])) b++;
			if((a[i+1]>a[i]&&a[i+1]>a[i+2]) || (a[i+1]<a[i]&&a[i+1]<a[i+2])) b++;
			int a1 = a[i];
			if(a[i]=a[i-1])
			{
				if((a[i-1]>a[i-2]&&a[i-1]>a[i]) || (a[i-1]<a[i-2]&&a[i-1]<a[i])) c++;
				if((a[i]>a[i-1]&&a[i]>a[i+1]) || (a[i]<a[i-1]&&a[i]<a[i+1])) c++;
				if((a[i+1]>a[i]&&a[i+1]>a[i+2]) || (a[i+1]<a[i]&&a[i+1]<a[i+2])) c++;
			}
			if(a[i] = a[i+1])
			{
				if((a[i-1]>a[i-2]&&a[i-1]>a[i]) || (a[i-1]<a[i-2]&&a[i-1]<a[i])) d++;
				if((a[i]>a[i-1]&&a[i]>a[i+1]) || (a[i]<a[i-1]&&a[i]<a[i+1])) d++;
				if((a[i+1]>a[i]&&a[i+1]>a[i+2]) || (a[i+1]<a[i]&&a[i+1]<a[i+2])) d++;
			}
			a[i] = a1;
			//int e  = min(min(tot,tot-b+c),tot-b+d);
			//minn = min(e,minn);
			minn=min(min(minn,tot-b+c),tot-b+d);
		}	 
		cout<<minn<<endl;
	}
 }