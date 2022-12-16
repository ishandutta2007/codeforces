#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
const int mod=998244353;
int main()
{
	ll n;
	cin>>n;
	ll ans=0,s=1,temp=1;
	for(int i=1;i<=n;i++) s=s*i%mod;
	ans+=s;
	for(ll i=n;i;i--)
	{
		temp*=i;
		temp%=mod;
		ans+=(s-temp+mod)%mod;
		if(ans>=mod) ans-=mod;
	}
	cout<<ans;
}