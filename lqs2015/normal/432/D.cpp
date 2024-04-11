#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[111111];
int l,r,z[111111],j,k,ans[111111],cnt,sz;
pair<int,int> res[111111];
int main()
{
	scanf("%s",s);
	sz=strlen(s);
	l=0;r=0;z[0]=sz;
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
	for (int i=0;i<sz;i++)
	{
		ans[z[i]]++;
	}
	for (int i=sz-1;i>=1;i--)
	{
		ans[i]+=ans[i+1];
	}
	for (int i=0;i<sz;i++)
	{
		if (i+z[i]==sz) 
		{
			res[++cnt]=make_pair(z[i],ans[z[i]]);
		}
	}
	sort(res+1,res+cnt+1);
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
	{
		printf("%d %d\n",res[i].first,res[i].second);
	}
	return 0;
}