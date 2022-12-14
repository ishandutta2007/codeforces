#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char s[1111111];
int l,r,sz,mx,j,z[1111111],k,ans;
int main()
{
	gets(s);
	sz=strlen(s);
	l=0;r=0;
	for (int i=1;i<sz;i++)
	{
		if (i>r)
		{
			for (j=0;j<sz;j++)
			{
				if (s[j]!=s[j+i]) break;
			}
			l=i;r=i+j-1;z[i]=j;
		}
		else
		{
			k=i-l;
			if (z[k]<r-i+1) 
			{
				z[i]=z[k];
			}
			else 
			{
				for (j=r;j<sz;j++)
				{
					if (s[j]!=s[j-i]) break;
				}
				l=i;r=j-1;z[i]=r-l+1;
			}
		}
	}
	for (int i=1;i<sz;i++)
	{
		if (z[i]+i==sz) mx=max(mx,z[i]-1);
		else mx=max(mx,z[i]);
	}
	for (int i=1;i<sz;i++)
	{
		if (z[i]+i==sz)
		{
			if (z[i]<=mx) ans=max(ans,z[i]);
		}
	}
	if (ans==0)
	{
		printf("Just a legend\n");
		return 0;
	}
	for (int i=0;i<ans;i++) printf("%c",s[i]);
	printf("\n");
	return 0;
}