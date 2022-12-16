#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=(f<<1)+(f<<3)+ch-'0';
	ch=getchar();}
	return f;
}
char s[100006],a[35],b[100005];bool ok[55],ac;
int main()
{
	scanf("%s",a+1);
	int x=strlen(a+1);
	for(int i=1;i<=x;i++)
	ok[a[i]-'a']=1;
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='*')
		ac=1;
	}
	int t=read();
	while(t--)
	{
		scanf("%s",b+1);
		int m=strlen(b+1);
		int len=m-n+1;
		if(!ac&&n!=m)
		{
			printf("NO\n");
			continue;
		}
		else if(len<0)
		{
			printf("NO\n");
			continue;
		}
		else
		{
			int temp=0;bool ak=1;
			for(int i=1;i<=n;i++)
			{
				if(s[i]!='*'&&s[i]!='?')
				{
					if(b[i+temp]!=s[i])
					{
						ak=0;
						break;
					}
				}
				else if(s[i]=='?')
				{
					if(!ok[b[i+temp]-'a'])
					{
						ak=0;
						break;
					}
				}
				else
				{
					bool acak=1;
					for(int j=0;j<len;j++)
					{
						if(ok[b[i+j]-'a'])
						{
							acak=0;
							break;
						}
					}
					if(!acak)
					{
						ak=0;
						break;
					}
					else
					temp=len-1;
				}
			}
			if(ak)
			printf("YES\n");
			else printf("NO\n");
		}
	}
}