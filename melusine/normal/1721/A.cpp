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
char s[10][10];
int sl[27];
int main()
{
	int t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s[1]+1);
		scanf("%s",s[2]+1);
		for(int i=0;i<=25;i++)sl[i]=0;
		for(int i=1;i<=2;i++)for(int j=1;j<=2;j++)sl[s[i][j]-'a']++;
		int ans=0;
		for(int i=0;i<=25;i++)
		{
			if(sl[i]!=0)ans++;
		}
		printf("%d\n",ans-1);
	} 
	return 0;
}