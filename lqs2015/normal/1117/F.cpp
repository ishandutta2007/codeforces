#include<bits/stdc++.h>
using namespace std;
int n,p,nxt[144444][22],msk[144444][22],ans,num[22],cur;
int f[144444],fake[144444],t[144444],fuck[144444][18][18];
char s[144444];
int fl[22][22];
void dfs(int i,int j,int k)
{
	fake[i]=1;
	if (i==(1<<p)-1) return;
	if (fuck[i][j][k]) return;
	fuck[i][j][k]=1;
	for (int h=0;h<p;h++)
	{
		if (h!=j && h!=k && !(i&(1<<h))) dfs(i^(1<<h),j,k);
	}
}
int main()
{
	scanf("%d%d",&n,&p);
	scanf("%s",s);
	for (int i=0;i<p;i++)
	{
		for (int j=0;j<p;j++)
		{
			scanf("%d",&fl[i][j]);
		}
	}
	for (int i=0;i<n;i++) num[s[i]-'a']++;
	for (int i=0;i<p;i++) nxt[n-1][i]=n;
	for (int i=n-2;i>=0;i--)
	{
		for (int j=0;j<p;j++)
		{
			nxt[i][j]=nxt[i+1][j];
		}
		nxt[i][s[i+1]-'a']=i+1;
	}
	for (int i=n-1;i>=0;i--)
	{
		for (int j=0;j<p;j++)
		{
			if (nxt[i][j]==i+1) msk[i][j]=0;
			else msk[i][j]=msk[i+1][j]|(1<<(s[i+1]-'a'));
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<p;j++)
		{
			if (!fl[s[i]-'a'][j] && nxt[i][j]<n)
			{
				if ((msk[i][j]&(1<<(s[i]-'a')) || (msk[i][j]&(1<<j)))) continue;
				dfs(msk[i][j],s[i]-'a',j);
			}
		}
	}
	for (int i=1;i<(1<<p);i++)
	{
		t[i]=1;
		if (fake[i]) continue;
		for (int j=0;j<p;j++)
		{
			if (i&(1<<j)) 
			{
				if (!t[i^(1<<j)]) t[i]=0;
			}
		}
	}
	ans=1e9;
	for (int i=0;i<(1<<p);i++)
	{
		if (!t[i])
		{
			cur=0;
			for (int j=0;j<p;j++)
			{
				if (!(i&(1<<j))) cur+=num[j];
			}
			ans=min(ans,cur);
		}
	}
	printf("%d\n",ans);
	return 0;
}