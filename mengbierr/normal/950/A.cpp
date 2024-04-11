#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inline  __attribute__((always_inline))
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int ans=0;
	ans+=min(a,b)*2;
	if(c<=max(a,b)-min(a,b))
	{
		ans+=c*2;
		cout<<ans;
		return 0;
	}
	else
	{
		ans+=(max(a,b)-min(a,b))*2;
		c-=max(a,b)-min(a,b);
		ans+=c/2*2;
		cout<<ans;
	}
}