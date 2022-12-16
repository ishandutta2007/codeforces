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
int main()
{
	int n=read();
	printf("%d\n",n+n/2);
	for(int i=2;i<=n;i+=2) printf("%d ",i);
	for(int i=1;i<=n;i+=2)  printf("%d ",i);
	for(int i=2;i<=n;i+=2) printf("%d ",i);
}