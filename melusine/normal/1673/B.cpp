#include<iostream>
#include<cstdio>
#include<cstring>
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
char s[200005];
bool vis[105];
int main()
{
	int t,n,zq=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		if(n==1)
		{
			printf("YES\n");
			continue;
		}
		zq=n;
		for(int i=2;i<=n;i++)
		{
			if(s[i]==s[1])
			{
				zq=i-1;
				break;
			}
		}
		for(int i=1;i<=26;i++)vis[i]=false;
		bool flag=true;
		for(int i=2;i<=zq;i++)
		{
			if(vis[s[i]-'a'+1]==true)
			{
				flag=false;
				break;
			}
			vis[s[i]-'a'+1]=true;
		}
		if(flag==false)
		{
			printf("NO\n");
			continue;
		}
		for(int i=zq+1;i<=n;i++)
		{
			if(s[i]!=s[i-zq])
			{
				flag=false;
				break;
			}
		}
		if(flag==false)printf("NO\n");
		else printf("YES\n");
	} 
	return 0;
}