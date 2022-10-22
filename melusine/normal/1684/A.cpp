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
char s[500005];
int main()
{
	int t,n,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		if(n==2)
		{
			printf("%c\n",s[2]);
			continue;
		}
		ans=10;
		for(int i=1;i<=n;i++)ans=min(ans,s[i]-'0');
		printf("%c\n",ans+'0');
	}
	return 0;
}