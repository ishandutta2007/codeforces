#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=205;
const ll inf=1e18;
int a[N][N],fa[N],from[N][N];
ll s[N][N],sum[N][N][N],f[N][N];
int dfs(int l,int r)
{
	if (l==r) return l;
	if (l>r) return 0;
	int x=from[l][r];
	fa[dfs(l,x-1)]=x;fa[dfs(x+1,r)]=x;
	return x;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,k,l;
	cin>>n;
	for (i=1;i<=n;i++) for (j=1;j<=n;j++) cin>>a[i][j];
	for (i=1;i<=n;i++) for (j=1;j<=n;j++) s[i][j]=s[i][j-1]+a[i][j];
	for (k=1;k<=n;k++) for (i=1;i<=n;i++) for (j=i;j<=n;j++) sum[i][j][k]=sum[i][j-1][k]+s[j][k];
	for (l=1;l<=n;l++) for (i=1;(j=i+l)<=n;i++)
	{
		//[i,j]
		f[i][j]=inf;
		for (k=i;k<=j;k++)
		{
			ll L=sum[i][k-1][n]-sum[i][k-1][k-1]+sum[i][k-1][i-1];
			ll R=sum[k+1][j][n]-sum[k+1][j][j]+sum[k+1][j][k];
			if (f[i][j]>L+R+f[i][k-1]+f[k+1][j])
			{
				from[i][j]=k;
				f[i][j]=L+R+f[i][k-1]+f[k+1][j];
			}
		}
		//[i,k)+(k,j]
	}
	//for (i=1;i<=n;i++) for (j=i;j<=n;j++) cerr<<i<<' '<<j<<' '<<f[i][j]<<" from "<<from[i][j]<<'\n';
	dfs(1,n);
	for (i=1;i<=n;i++) cout<<fa[i]<<" \n"[i==n];
}