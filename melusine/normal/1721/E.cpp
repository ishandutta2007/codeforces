#include<iostream>
#include<cstdio>
#include<map>
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
char s[1100005];
int kmp[1100005],nex[1100005][26];
char t[1100005];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	kmp[1]=0;
	int sth=0;
	for(int i=2;i<=n;i++)
	{
		while(sth!=0&&s[sth+1]!=s[i])sth=kmp[sth];
		if(s[sth+1]==s[i])sth++;
		kmp[i]=sth;
	}
	nex[0][s[1]-'a']=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=25;j++)nex[i][j]=nex[kmp[i]][j];
		if(i!=n)nex[i][s[i+1]-'a']=i+1;
	}
	int q;
	q=read();
	for(int j=1;j<=q;j++)
	{
		scanf("%s",t+1);
		int now=kmp[n],m=strlen(t+1);
		for(int i=1;i<=m;i++)s[n+i]=t[i],kmp[n+i]=0;
		for(int i=1;i<=m;i++)
		{
			if(t[i]==s[now+1])now++;
			else 
			{
				while(now>n&&s[now+1]!=t[i])now=kmp[now];
				if(s[now+1]==t[i])now++;
				else now=nex[now][t[i]-'a'];
			}
			kmp[n+i]=now;
			printf("%d ",now);
		}
		printf("\n");
	}
	return 0;
}