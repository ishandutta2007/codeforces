#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[33];
bool flag;
int n,ans,p;
char c[333333],op;
bool check()
{
	int res1=0,res2=0;
	for (int i=0;i<26;i++)
	{
		if (!f[i]) res1++;
		if (f[i]==1) res2++;
	}
	if (res1==25 || res2==1) return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<26;i++) f[i]=2;
	for (int i=1;i<=n;i++)
	{
		getchar();
		scanf("%c %s",&op,c);
		if (op=='!')
		{
			if (flag) ans++;
			else
			{
				p=strlen(c);
				for (int j=0;j<p;j++)
				{
					if (f[c[j]-'a']==2) f[c[j]-'a']=1;
				}
				for (int j=0;j<26;j++)
				{
					if (!f[j]) continue;
					bool ff=0;
					for (int k=0;k<p;k++)
					{
						if (c[k]-'a'==j) ff=1;
					}
					f[j]=ff;
				}
			}
		}
		else if (op=='.')
		{
			p=strlen(c);
			for (int j=0;j<p;j++)
			{
				f[c[j]-'a']=0;
			}
		}
		else if (op=='?')
		{
			if (flag)
			{
				if (i!=n) ans++;
			}
			else
			{
				f[c[0]-'a']=0;
			}
		}
		if (!flag && check()) flag=1;
	}
	printf("%d\n",ans);
	return 0;
}