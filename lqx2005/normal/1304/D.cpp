#include<bits/stdc++.h>
using namespace std;
const int maxn=200000;
int T,n;
char s[maxn+5];
int to[maxn+5];
int ans[maxn+5];
int main()
{
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%d",&n);
		scanf("%s",s+2);
		int tot=0;
		to[n]=n;
		for(int i=n-1;i>=1;i--)
		{
			if(s[i+1]=='>') to[i]=i;
			else to[i]=to[i+1];
		}
		tot=n+1;
		for(int i=1;i<=n;i++)
		{
			for(int j=to[i];j>=i;j--)
			{
				ans[j]=--tot;
			}
			i=to[i];
		}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
		tot=0;
		to[n]=n;
		for(int i=n-1;i>=1;i--)
		{
			if(s[i+1]=='<') to[i]=i;
			else to[i]=to[i+1];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=to[i];j>=i;j--)
			{
				ans[j]=++tot;
			}
			i=to[i];
		}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}