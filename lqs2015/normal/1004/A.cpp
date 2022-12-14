#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[111],d,n,ans,cur;
int main()
{
	cin>>n>>d;
	for (int i=1;i<=n;i++) cin>>a[i];
	ans=2;
	for (int i=1;i<n;i++)
	{
		cur=a[i]+d;
		if (abs(a[i+1]-cur)>=d) ans++;
		cur=a[i+1]-d;
		if (abs(a[i]-cur)>d) ans++;
	}
	cout<<ans<<endl;
	return 0;
 }