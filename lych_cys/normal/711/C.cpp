#include<bits/stdc++.h>
#define ll long long
#define N 105
using namespace std;

int n,m,cnt,c[N]; ll dp[N][N][N],f[N][N][N],g[N][N][N],a[N][N];
int read(){
	int x=0; char cr=getchar(); bool flag=0;
	while (cr<'0' || cr>'9'){ if (cr=='-') flag=1; cr=getchar(); }
	while (cr>='0' && cr<='9'){ x=x*10+cr-'0'; cr=getchar(); }
	return (flag)?-x:x;
}
int main(){
	scanf("%d%d%d",&n,&m,&cnt);
	if (cnt>n){ puts("-1"); return 0; }
	int i,j,k,l;
	for (i=1; i<=n; i++) scanf("%d",&c[i]);
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++) scanf("%lld",&a[i][j]);
	for (i=1; i<=n; i++)
		if (c[i]){
			for (j=1; j<=m; j++)a[i][j]=1000000000000000000ll;
			a[i][c[i]]=0;}
	for (i=1; i<=n; i++)
		for (j=0; j<=n; j++)
			for (k=0; k<=m+1; k++) dp[i][j][k]=f[i][j][k]=g[i][j][k]=1000000000000000000ll;
	for (i=1; i<=m; i++){ dp[1][1][i]=a[1][i]; f[1][1][i]=min(f[1][1][i-1],dp[1][1][i]);}
	for (i=m; i; i--)g[1][1][i]=min(g[1][1][i+1],dp[1][1][i]);
	for (i=2; i<=n; i++)
		for (j=1; j<=n; j++){
			for (k=1; k<=m; k++){
				dp[i][j][k]=min(min(f[i-1][j-1][k-1],g[i-1][j-1][k+1]),dp[i-1][j][k]);
				dp[i][j][k]+=a[i][k];
				f[i][j][k]=min(f[i][j][k-1],dp[i][j][k]);
			}
			for (k=m; k; k--) g[i][j][k]=min(g[i][j][k+1],dp[i][j][k]);
			}
	if (f[n][cnt][m]==1000000000000000000ll)puts("-1"); else
	printf("%lld\n",f[n][cnt][m]);
	return 0;
}