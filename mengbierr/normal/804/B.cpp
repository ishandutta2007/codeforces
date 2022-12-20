#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}
char s[1000005];
int mod=1000000007;
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);long long ans=0,now=0;
	for(int i=n;i;i--)
	{
		if(s[i]=='b')
		now++;
		else
		{
			ans+=now;
			ans%=mod;
			now=(now+now)%mod;
		}
	}
	cout<<ans;
}