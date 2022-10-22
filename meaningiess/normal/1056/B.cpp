#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll n,m,i,j,ans,a[1010][1010],b[1010];
int main()
{
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		ll s=0;
		for (j=1;j<=m;j++) if ((i*i+j*j)%m==0) a[i][j]++,s++;
		b[i]+=s*(n/m);
		for (j=1;j<=n%m;j++) b[i]+=a[i][j];
		ans+=b[i];
	}
	ans*=(n/m);
	for (i=1;i<=n%m;i++) ans+=b[i];
	cout<<ans;
}