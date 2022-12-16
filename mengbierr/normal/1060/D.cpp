#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<ctime>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int a[100005],b[100005],n;
ll ans;
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		ans+=max(a[i],b[i]);
	}
	cout<<ans+n;
}