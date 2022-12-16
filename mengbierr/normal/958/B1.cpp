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
int du[100005],n;
int main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		du[x]++;du[y]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(du[i]==1)
		{
			ans++;
		}
	}
	cout<<ans;
}