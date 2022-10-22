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
char s[100005];
int main()
{
	int t,n,ans=0,pr;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		pr=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')continue;
			if(pr==0)
			{
				pr=i;
				continue;
			}
			ans+=max(0,2-(i-pr-1));
			pr=i;
		}
		printf("%d\n",ans);
	}
}