#include<iostream>
#include<cstdio>
using namespace std;
char s[222222];
int t,n,pos,ppos;
int main()
{
	scanf("%d%d",&n,&t);
	scanf("%s",s);
	for (int i=0;i<n;i++)
	{
		if (s[i]=='.')
		{
			pos=i;
			break;
		}
	}
	for (int i=pos+1;i<n;i++)
	{
		if (s[i]>='5')
		{
			ppos=i;
			break;
		}
	}
	if (!ppos)
	{
		printf("%s\n",s);
	}
	else
	{
		t--;ppos--;
		while(s[ppos]=='9')
		{
			s[ppos]='0';
			ppos--;
		}
		if (s[ppos]=='.') 
		{
			ppos--;
			while(s[ppos]=='9' && ppos>=0)
			{
				s[ppos]='0';
				ppos--;
			}
			if (ppos==-1)
			{
				printf("1");
				for (int i=1;i<=pos;i++) printf("0");
				printf("\n");
				return 0;
			}
		}
		s[ppos]++;
		while(t && ppos>pos)
		{
			if (s[ppos]<'5') break;
			t--;ppos--;
			while(s[ppos]=='9')
			{
				s[ppos]='0';
				ppos--;
			}
			if (s[ppos]=='.') 
			{
				ppos--;
				while(s[ppos]=='9' && ppos>=0)
				{
					s[ppos]='0';
					ppos--;
				}
				if (ppos==-1)
				{
					printf("1");
					for (int i=1;i<=pos;i++) printf("0");
					printf("\n");
					return 0;
				}
			}
			s[ppos]++;
		}
		for (int i=0;i<=max(ppos,pos-1);i++) printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}