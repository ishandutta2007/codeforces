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
long long ans=1;
int a[105];
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	long long now=0;bool ac=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0&&ac)
		now++;
		if(a[i]==1&&!ac) ac=1;
		else if(a[i]==1)
		{
			ans=ans*(now+1);
			now=0;
		}
	}
	if(!ac)
	printf("0");
	else printf("%lld",ans);
}