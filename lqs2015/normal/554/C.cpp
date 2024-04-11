#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long mod=1000000007;
long long n,a[1111],s,ans,t,g;
long long c[1111][1111];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	ans=1;
	for (int i=0;i<=s;i++) c[i][0]=1;
	for (int i=0;i<=s;i++) c[i][i]=1;
	for (int i=2;i<=s;i++)
	{
		for (int j=1;j<i;j++)
		{
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	for (int i=1;i<=n;i++)
	{
		g=a[i]-1;
		t=0;
		for (int j=1;j<i;j++) 
		t+=a[j];
		t+=g;
		ans=ans*c[t][g]%mod;
	}
	ans=ans%mod;
	cout<<ans<<endl;
	return 0;
}