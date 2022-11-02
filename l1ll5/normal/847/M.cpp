#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int n;
int a[105];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	bool ac=1;int now,temp;
	now=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=now)
		{
			ac=0;
			break;
		}
	}
	if(!ac)
	printf("%d",a[n]);
	else printf("%d",a[n]+now);
}