#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
ll n;
int main()
{
	cin>>n;
	ll now=0;
	while(now*10+9<=n) now=now*10+9;
	ll x=n-now;
	ll ans=0;
	while(x!=0)
	{
		ans+=x%10;
		x/=10;
	}
	while(now!=0)
	{
		ans+=now%10;
		now/=10;
	}
	cout<<ans;
}