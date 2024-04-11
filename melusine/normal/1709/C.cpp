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
signed main()
{
	int t,n,sl1,sl2,x;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		sl1=0;
		sl2=0;
		for(int i=1;i<=n;i++)
		{	
			if(s[i]=='(')sl1++;
			if(s[i]==')')sl2++;
		}
		sl1=n/2-sl1;
		sl2=n/2-sl2;
		//printf("%d %d\n",sl1,sl2);
		if(sl1==0||sl2==0)
		{
			printf("YES\n");
			continue;
		}
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!='?')continue;
			if(sl1>1)
			{
				s[i]='(';
				sl1--;
			}
			else if(sl1==1&&flag==false)
			{
				s[i]=')';
				sl2--;
				flag=true;
			}
			else if(sl1==1&&flag==true)
			{
				s[i]='(';
				sl1--;
			}
			else if(sl1==0)
			{
				s[i]=')';
				sl2--;
			}
		}
		//printf("%s\n",s+1);
		flag=true;
		x=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='(')x++;
			else x--;
			if(x<0)
			{
				flag=false;
				break;
			}
		}
		if(flag==false)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}