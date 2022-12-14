#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,maxn=62;
int n,cnt,mat[66][66],b[222222],e[222222],dp[66][66][66],ans,a,B,c,d;
string s[222222],str;
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int get(char c)
{
	if (c>='a' && c<='z') return c-'a';
	else if (c>='A' && c<='Z') return c+26-'A';
	return c+52-'0';
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>str;
		s[(i<<1)-1]=str;
		reverse(str.begin(),str.end());
		s[i<<1]=str;
	}
	sort(s+1,s+2*n+1);
	cnt=unique(s+1,s+2*n+1)-s-1;
	for (int i=1;i<=cnt;i++)
	{
		b[i]=get(s[i][0]);e[i]=get(s[i][(int)s[i].size()-1]);
	}
	for (int i=3;i<=10;i++)
	{
		memset(mat,0,sizeof(mat));
		memset(dp,-1,sizeof(dp));
		for (int j=1;j<=cnt;j++)
		{
			if ((int)s[j].size()==i) mat[b[j]][e[j]]++;
		}
		for (int j=0;j<maxn;j++)
		{
			for (int k=j;k<maxn;k++)
			{
				for (int h=k;h<maxn;h++)
				{
					dp[j][k][h]=0;
					for (int p=0;p<maxn;p++)
					{
						add(dp[j][k][h],1ll*mat[j][p]*mat[k][p]%mod*mat[h][p]%mod);
					}
				}
			}
		}
		for (int i=0;i<maxn;i++)
		{
			for (int j=0;j<maxn;j++)
			{
				for (int k=0;k<maxn;k++)
				{
					if (dp[i][j][k]==-1)
					{
						a=i;B=j;c=k;
						if (a>B) swap(a,B);
						if (B>c) swap(B,c);
						if (a>c) swap(a,c);
						dp[i][j][k]=dp[a][B][c];
					}
				}
			}
		}
		for (int j=0;j<maxn;j++)
		{
			for (int k=j;k<maxn;k++)
			{
				if (k>j) a=1;
				else a=0;
				for (int h=k;h<maxn;h++)
				{
					if (h>k) c=1;
					else c=0;
					d=0;
					for (int p=h;p<maxn;p++)
					{
						if (a&c&d) add(ans,24ll*dp[j][k][h]%mod*dp[k][h][p]%mod*dp[j][k][p]%mod*dp[j][h][p]%mod);
						else if ((a&c) || (c&d) || (a&d)) add(ans,12ll*dp[j][k][h]%mod*dp[k][h][p]%mod*dp[j][k][p]%mod*dp[j][h][p]%mod);
						else if (a || d) add(ans,4ll*dp[j][k][h]*dp[k][h][p]%mod*dp[j][k][p]%mod*dp[j][h][p]%mod);
						else if (c) add(ans,6ll*dp[j][k][h]*dp[k][h][p]%mod*dp[j][k][p]%mod*dp[j][h][p]%mod);
						else add(ans,1ll*dp[j][k][h]*dp[k][h][p]%mod*dp[j][k][p]%mod*dp[j][h][p]%mod);
						d=1;
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}