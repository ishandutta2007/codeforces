#include<bits/stdc++.h>
using namespace std;
int T,n,t,l,ll,ans;
char a[1000005];
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		ll=0;ans=INT_MAX;
		t=n;
		while (t>=1&&a[t]=='1') t--;
		l=1;
		while (l<=n&&a[l]=='0') l++;
		for (int i=l;i<=t;i++)
		  if (a[i]=='0') ll++,ans=min(ans,ll);
		  else ll=0;
		if (ans==INT_MAX) ans=0;
		for (int i=1;i<l;i++) cout<<'0';
		for (int i=1;i<=ans;i++) cout<<'0';
		for (int i=1;i<=n-t;i++) cout<<'1';cout<<endl;
	}
}