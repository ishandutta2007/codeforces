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
int sl[27];
char s[100005];
int main()
{
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		scanf("%s",s+1);
		for(int i=1;i<=26;i++)sl[i]=0;
		for(int i=1;i<=n;i++)sl[s[i]-'a'+1]++;
		for(int i=1;i<=k;i++)
		{
			int now=1;
			for(int j=1;j<=min(25,n/k);j++)
			{
				if(sl[j]==0)
				{
					break;
				}
				sl[j]--;
				now++;
			}
			printf("%c",now+'a'-1);
		}
		printf("\n");
	}
	return 0;
}