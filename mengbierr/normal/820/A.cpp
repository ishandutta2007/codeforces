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
int main()
{
	int c=read(),v0=read(),v1=read(),a=read(),l=read();
	int now=v0,day=1,page=v0;
	while(now<c)
	{
		day++;
		page+=a;
		if(page>v1)
		page=v1;
		now+=page;
		now-=l;
		if(now>=c)
		break;
	}
	printf("%d",day);
}