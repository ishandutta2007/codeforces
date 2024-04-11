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
int main()
{
	int t,n,het=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		het=0;
		for(int i=1;i<=n;i++)
		{
			het+=(s[i]-'a'+1);
		}
		if(n%2==0)printf("Alice %d\n",het);
		else
		{
			het=het-2*min(s[1]-'a'+1,s[n]-'a'+1);
			if(het>0)printf("Alice %d\n",het);
			else printf("Bob %d\n",-het);
		}
	} 
	return 0;
}