#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
char s[25],t[25];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)t[i]=s[i];
	for(int i=1;i<=n;i++)
	{
		for(int j='a';j<='z';j++)
		{
			if(j==s[i])continue;
			s[i]=j;
			bool ac=1;
			for(int k=1;k<=n;k++)
			{
				if(s[k]!=s[n-k+1])
				{
					ac=0;
					break;
				}
			}
			if(ac)
			{
				printf("YES");
				return 0;
			}
			s[i]=t[i];
		}
	}
	printf("NO");
}