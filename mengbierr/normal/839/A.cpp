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
int n,k,a[100005];
int main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	int now=0,tot=0;
	for(int i=1;i<=n;i++)
	{
		now+=a[i];
		if(now>=8)
		{
			now-=8;
			tot+=8;
		}
		else
		{
			tot+=now;
			now=0;
		}
		if(tot>=k)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}