#include<iostream>
#include<cstdio>
using namespace std;
const long long mod=1e9+7;
long long n,ans;
char s[111111];
long long num[5],mx,cnt;
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++)
	{
		if (s[i]=='A') num[1]++;
		else if (s[i]=='C') num[2]++;
		else if (s[i]=='G') num[3]++;
		else num[4]++;
	}
	for (int i=1;i<=4;i++)
	{
		mx=max(mx,num[i]);
	}
	for (int i=1;i<=4;i++)
	{
		if (num[i]==mx) cnt++;
	}
	ans=1ll;
	for (int i=1;i<=n;i++)
	{
		ans=ans*cnt%mod;
	}
	cout<<ans<<endl;
	return 0;
}