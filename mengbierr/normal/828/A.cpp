#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=(f<<1)+(f<<3)+ch-'0';
	ch=getchar();}
	return f;
}
int ans,c[200005];
int main()
{
	int n=read(),a=read(),b=read(),cc=0;
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==2)
		{
			if(!b)
			{
				ans+=2;
			}
			else
			{
				b--;
			}
		}
		else
		{
			if(a)
			{
				a--;
			}
			else if(b)
			{
				b--;
				cc++;
			}
			else if(cc)
			{
				cc--;
			}
			else
			{
				ans++;
			}
		}
	}
	cout<<ans;
}