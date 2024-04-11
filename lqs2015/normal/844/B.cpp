#include<iostream>
#include<cmath>
using namespace std;
long long a[55][55],cnt0,cnt1,n,m,ans;
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		cin>>a[i][j];
	}
	for (int i=1;i<=n;i++)
	{
		cnt0=cnt1=0;
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]) cnt1++;
			else cnt0++;
		}
		ans=ans+pow(2ll,cnt0)+pow(2ll,cnt1)-2ll;
	}
	for (int j=1;j<=m;j++)
	{
		cnt0=cnt1=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i][j]) cnt1++;
			else cnt0++;
		}
		ans=ans+pow(2ll,cnt0)+pow(2ll,cnt1)-2ll-cnt0-cnt1;
	}
	cout<<ans<<endl;
	return 0;
}