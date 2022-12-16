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
	int n=read();int a,b,c,d;
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a=abs(a);b=abs(b);
		if(a%2==1&&b%2==1)
		printf("1\n");
		else if(a%2==1&&b%2==0)
		printf("2\n");
		else if(a%2==0&&b%2==0)
		printf("3\n");
		else printf("4\n");
	}
}