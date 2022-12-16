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
int a[500005];
int main()
{
	int t=read();
	while(t--)
	{
		int n=read(),u=read(),v=read();
		for(int i=1;i<=n;i++)a[i]=read();
		bool ok=1,in=1;
		int maxx=a[1],minn=a[1];
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[1]) ok=0;
			maxx=max(maxx,a[i]);
			minn=min(minn,a[i]);
			if(abs(a[i]-a[i-1])>1) in=0;
		}
		if(!in) puts("0");
		else
		{
			if(!ok) cout<<min(u,v)<<endl;
			else cout<<min(u+v,2*v)<<endl;
		}
	}
}