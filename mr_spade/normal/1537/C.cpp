#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,x;
int a[N];
inline void solve()
{
	register int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	x=2;
	for(i=3;i<=n;i++)
		if(a[i]-a[i-1]<a[x]-a[x-1])
			x=i;
	if(a[n]-a[1]<=a[x]-a[x-1])
	{
		for(i=1;i<=n;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	else
	{
		for(i=x;i<=n;i++)
			cout<<a[i]<<' ';
		for(i=1;i<=x-1;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}