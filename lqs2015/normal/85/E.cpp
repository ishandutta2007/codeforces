#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,x[5555],y[5555],X[5555],Y[5555],u,d,l,r,mn,a,b,ans;
int main()
{
	scanf("%d",&n);
	d=l=1e9;u=r=-1e9;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		X[i]=x[i]+y[i];Y[i]=x[i]-y[i];
		u=max(u,X[i]);d=min(d,X[i]);l=min(l,Y[i]);r=max(r,Y[i]);
	}
	for (int i=1;i<=n;i++)
	{
		a=max(a,min(max(abs(u-X[i]),abs(l-Y[i])),max(abs(d-X[i]),abs(r-Y[i]))));
		b=max(b,min(max(abs(u-X[i]),abs(r-Y[i])),max(abs(d-X[i]),abs(l-Y[i]))));
	}
	mn=min(a,b);
	printf("%d\n",mn);
	ans=1;
	for (int i=1;i<=n;i++)
	{
		if (abs(u-X[i])<=mn && abs(d-X[i])<=mn && abs(l-Y[i])<=mn && abs(r-Y[i])<=mn) ans=ans*2%mod;
	}
	ans=ans*2%mod;
	if (a==b && l+mn<r && d+mn<u) ans=ans*2%mod;
	printf("%d\n",ans);
	return 0;
}