#include<bits/stdc++.h>
using namespace std;

int n;
char s[110];
int main()
{
	int te;
	scanf("%d",&te);
	for (int ca=1;ca<=te;ca++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int m1=0,m2=0,m3=0;
		for (int i=1;i<=n;i++)
		{
			if (s[i]<='9' && s[i]>='0')	m1++;
			if (s[i]<='z' && s[i]>='a')	m2++;
			if (s[i]<='Z' && s[i]>='A')	m3++;
		}
		if (m1==0 && m2==0)
		{
			s[1]='0';
			s[2]='z';
		}	else
		if (m1==0 && m3==0)
		{
			s[1]='0';
			s[2]='Z';
		}	else
		if (m2==0 && m3==0)
		{
			s[1]='z';
			s[2]='Z';
		}	else
		if (m1==0)
		{
			for (int i=1;i<=n;i++)
			{
				if (s[i]<='z' && s[i]>='a' && m2>1)	{s[i]='0';break;}
				if (s[i]<='Z' && s[i]>='A' && m3>1)	{s[i]='0';break;}
			}
		}	else
		if (m2==0)
		{
			for (int i=1;i<=n;i++)
			{
				if (s[i]<='9' && s[i]>='0' && m1>1)	{s[i]='z';break;}
				if (s[i]<='Z' && s[i]>='A' && m3>1)	{s[i]='z';break;}
			}
		}	else
		if (m3==0)
		{
			for (int i=1;i<=n;i++)
			{
				if (s[i]<='z' && s[i]>='a' && m2>1)	{s[i]='Z';break;}
				if (s[i]<='9' && s[i]>='0' && m1>1)	{s[i]='Z';break;}
			}
		}
		printf("%s\n",s+1);
	}
	return 0;
}