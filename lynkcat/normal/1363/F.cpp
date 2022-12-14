// LUOGU_RID: 93606267
// Lynkcat.
// Problem: B. Rotating Substrings
// Contest: Codeforces - 11.11
// URL: https://codeforces.com/gym/409566/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 2005 
using namespace std;
int n,pre[N][2][26];
int f[N][N];
void BellaKira()
{
	cin>>n;
	string st,st1;
	cin>>st>>st1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=1;j++)
			for (int k=0;k<26;k++) pre[i][j][k]=pre[i-1][j][k];
		pre[i][0][st[i-1]-'a']++;
		pre[i][1][st1[i-1]-'a']++;
		if (i==n)
		{
			for (int j=0;j<26;j++)
				if (pre[n][0][j]!=pre[n][1][j]) return cout<<"-1\n",void();
		}
	}
	for (int i=0;i<=n;i++) f[0][i]=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
		{
			f[i][j]=f[i-1][j]+1;
			if (st[i-1]==st1[j-1])
				f[i][j]=min(f[i][j],f[i-1][j-1]);
			if (pre[i][0][st1[j-1]-'a']<pre[j][1][st1[j-1]-'a'])
				f[i][j]=min(f[i][j],f[i][j-1]);
		}
	cout<<f[n][n]<<'\n';
	for (int i=0;i<=n;i++)
		for (int j=i;j<=n;j++) f[i][j]=f[n+1][n+1];
}
signed main()
{
	memset(f,0x3f,sizeof(f));
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}