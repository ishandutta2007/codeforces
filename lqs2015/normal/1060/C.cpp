#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a[2222],b[2222],x,mna[2222],mnb[2222],cur,ans;
int main()
{
	cin>>n>>m;
	for (long long i=1;i<=n;i++) cin>>a[i];
	for (long long i=1;i<=m;i++) cin>>b[i];
	cin>>x;
	for (long long i=1;i<=n;i++)
	{
		mna[i]=1e18;
	}
	for (long long i=1;i<=n;i++)
	{
		cur=0;
		for (long long j=i;j<=n;j++)
		{
			cur+=a[j];
			mna[j-i+1]=min(mna[j-i+1],cur);
		}
	}
	for (long long i=1;i<=m;i++)
	{
		mnb[i]=1e18;
	}
	for (long long i=1;i<=m;i++)
	{
		cur=0;
		for (long long j=i;j<=m;j++)
		{
			cur+=b[j];
			mnb[j-i+1]=min(mnb[j-i+1],cur);
		}
	}
	for (long long i=1;i<=n;i++)
	{
		for (long long j=1;j<=m;j++)
		{
			if (mna[i]*mnb[j]<=x) ans=max(ans,i*j);
		}
	}
	cout<<ans<<endl;
	return 0;
}