#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,K,a[505][505],f[505][505][2],rs[505][505],dp[505][505],c[505];char s[505];
int main()
{
	read(n),read(m),read(K),memset(rs,0x3f,sizeof(rs)),memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++) {scanf("%s",s+1);for(int j=1;j<=m;j++)a[i][j]=s[j]-'0';}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;for(int j=1;j<=m;j++) if(a[i][j])f[i][cnt++][0]=j;
		cnt=0;for(int j=m;j>=1;j--) if(a[i][j])f[i][cnt++][1]=j;
		c[i]=cnt;for(int j=0;j<=cnt;j++) for(int k=0;k+j<=cnt;k++)
			if(j+k==cnt) rs[i][j+k]=0;else rs[i][j+k]=min(rs[i][j+k],f[i][k][1]-f[i][j][0]+1);
	}
	for(int i=0;i<=c[1];i++) dp[1][i]=rs[1][i];
	for(int i=2;i<=n;i++) for(int j=0;j<=min(K,c[i]);j++) for(int k=0;k+j<=K;k++) dp[i][j+k]=min(dp[i][j+k],dp[i-1][k]+rs[i][j]);
	int res=1e9;for(int i=0;i<=K;i++)res=min(res,dp[n][i]);
	return printf("%d\n",res),0;
}