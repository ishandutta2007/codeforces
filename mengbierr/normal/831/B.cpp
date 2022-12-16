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
char s[50],t[50],a[2005];
int main()
{
	scanf("%s%s",s+1,t+1);
	scanf("%s",a+1);
	int n=strlen(a+1);
	for(int i=1;i<=n;i++)
	{
		if((a[i]>'z'||a[i]<'a')&&(a[i]>'Z'||a[i]<'A'))
		{cout<<a[i];
		continue;
		}
		for(int j=1;j<=26;j++)
		{
			if(s[j]==a[i])
			{cout<<t[j];
			continue;
			}
			else if(a[i]==s[j]+'A'-'a')
			{
				cout<<(char)(t[j]+'A'-'a');
			}
		}
	}
}