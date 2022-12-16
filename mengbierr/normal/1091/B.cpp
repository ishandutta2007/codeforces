#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#define ll long long
#define pii pair<int,int>
using namespace std;
map<pii,int> mp;
queue<pii> q,q1;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int a[1005],b[2005],c[2005],d[2005];
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		mp[pii(x,y)]=i;
		c[i]=x;d[i]=y;
	}
	for(int i=1;i<=n;i++)
	{
		int plax=a[1]+c[i],play=b[1]+d[i];
		bool ac=1;
		for(int j=1;j<=n;j++)
		{
			if(!mp[pii(plax-a[j],play-b[j])])
			{
				ac=0;
				break;
			}
		}
		if(ac)
		{
			cout<<plax<<" "<<play<<endl;
			return 0;
		}
	}
}