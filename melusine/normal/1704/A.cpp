#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char s[200005],t[200005]; 
int main()
{
	int ttt,n,m;
	ttt=read();
	for(int greg=1;greg<=ttt;greg++)
	{
		n=read();
		m=read();
		scanf("%s",s+1);
		scanf("%s",t+1);
		bool flag=true;
		for(int i=2;i<=m;i++)
		{
			if(t[i]!=s[i+n-m])
			{
				flag=false;
				break;
			}
		}
		if(flag==false)
		{
			printf("No\n");
			continue;
		}
		flag=false;
		for(int i=1;i<=n-m+1;i++)
		{
			if(s[i]==t[1])
			{
				flag=true;
				break;
			}
		}
		if(flag==true)printf("Yes\n");
		else printf("No\n");
	}
}