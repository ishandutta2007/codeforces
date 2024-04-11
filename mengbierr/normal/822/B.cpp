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
char s[1005],t[1005];int ans=2000000000;
int main()
{
	int n=read(),m=read();
	scanf("%s%s",s+1,t+1);
	int temp=0,pla;
	for(int i=1;i<=m-n+1;i++)
	{
		temp=0;
		for(int j=1;j<=n;j++)
		{
			if(s[j]!=t[j+i-1])
			temp++;
		}
		//cout<<temp<<" ";
		if(temp<ans)
		{
			ans=temp;
			pla=i;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=t[pla+i-1])
		printf("%d ",i);
	}
}