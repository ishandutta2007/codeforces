#include<iostream>
#include<cstdio>
#define mod 998244353
using namespace std;
char a[200010],b[200010];
int pw[200010],res[200010];
int main()
{
	int n,m,i,ans=0;cin>>n>>m;scanf("%s",a+1);scanf("%s",b+1);
	for (i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
	for (i=1;i<=m/2;i++) swap(b[i],b[m-i+1]);
	pw[1]=1;res[1]=a[1]-'0';
	for (i=2;i<=n;i++)
	{
		pw[i]=pw[i-1]*2;pw[i]%=mod;res[i]=res[i-1];
		if (a[i]=='1') res[i]+=pw[i];res[i]%=mod;
	}
	for (i=1;i<=m;i++)
	{
		if (b[i]=='0') continue;
		if (i<=n) ans+=res[i],ans%=mod;
		else ans+=res[n],ans%=mod;
	}
	cout<<ans;
}