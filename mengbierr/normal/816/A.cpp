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
	int x=read(),y=read(),ans=0;
	while(x/10+(x%10)*10!=y)
	{
		y++;
		ans++;
		if(y==60)
		{
			if(x==23)
			x=0;
			else x++;
			y=0;
		}
	}
	printf("%d",ans);
}