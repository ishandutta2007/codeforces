#include<bits/stdc++.h>
using namespace std;
const int maxn=500;
int T;
int n,m;
char s[maxn],t[maxn],a[maxn],b[maxn];
int dp[maxn][maxn];
int nxt[maxn][26];
void chm(int &x,int y)
{
	if(x==-1||y<x) x=y;
	return;
}
void updata(int sa,int sb)
{
	for(int i=0;i<=sa;i++) for(int j=0;j<=sb;j++) dp[i][j]=-1;
	dp[0][0]=0;
	for(int i=0;i<=sa;i++)
	{
		for(int j=0;j<=sb;j++)
		{
			if(dp[i][j]==-1) continue;
			int pa=i<sa?nxt[dp[i][j]+1][a[i+1]-'a']:-1;
			int pb=j<sb?nxt[dp[i][j]+1][b[j+1]-'a']:-1;
			if(pa!=-1) chm(dp[i+1][j],pa);
			if(pb!=-1) chm(dp[i][j+1],pb);
		}
	}
	return;
}
int main()
{
	scanf("%d",&T);
	for(int am=1;am<=T;am++)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		for(int i=0;i<=n+1;i++) for(int j=0;j<=25;j++) nxt[i][j]=-1;
		for(int i=n;i>=1;i--)
		{
			for(int j=0;j<=25;j++) nxt[i][j]=nxt[i+1][j];
			nxt[i][s[i]-'a']=i;
		} 
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=i;j++) a[j]=t[j];
			for(int j=i+1;j<=m;j++) b[j-i]=t[j];
			updata(i,m-i);
			if(dp[i][m-i]!=-1) ans=1;
		}
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}