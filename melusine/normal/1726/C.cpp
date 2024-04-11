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
char s[200005];
int main()
{
	int t,n,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		ans=n;
		for(int i=1;i<=2*n-1;i++)if(s[i]==')'&&s[i+1]=='(')ans--;
		printf("%d\n",ans);
	}
	return 0;
}