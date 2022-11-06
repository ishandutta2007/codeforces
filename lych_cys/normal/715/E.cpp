#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define N 255
using namespace std;

int n,tx,ty,bas,blk,cnt[2],a[2][N],b[2][N],cbn[N][N],per[N][N],dp[N][N],f[N],g[N],h[N],ans[N]; bool vis[2][N];
void dfs(int p,int k){
	if (vis[p][k] || !a[p][k]) return;
	tx=p; ty=k; vis[p][k]=1;
	dfs(p^1,k);  dfs(p^1,b[p^1][a[p][k]]);
}
void work(int f[],int cnt){
	int i,j;
	for (i=cnt; i>=0; i--){
		for (j=0; j<=cnt; j++) f[i]=(f[i]+(ll)cbn[cnt][j]*dp[j][i]%mod*per[cnt+blk-j][cnt-j])%mod;
		for (j=i+1; j<=cnt; j++) f[i]=(f[i]-(ll)f[j]*cbn[j][i]%mod+mod)%mod;	
	}
}
int main(){
	scanf("%d",&n);
	int i,j;
	for (i=1; i<=n; i++){ scanf("%d",&a[0][i]); b[0][a[0][i]]=i; }
	for (i=1; i<=n; i++){ scanf("%d",&a[1][i]); b[1][a[1][i]]=i; }
	for (i=1; i<=n; i++) if ((a[0][i]>0 ^ a[1][i]>0) && !vis[a[1][i]>0][i]){
		dfs(j=(a[1][i]>0),i);
		if (j^tx) blk++;
		if (j==tx) cnt[j]++;
	} else blk+=(!a[0][i] && !a[1][i]);
	for (i=1; i<=n; i++) if (a[0][i] && a[1][i] && !vis[0][i]){
		dfs(0,i);
		if (a[0][i]==a[tx][ty]) bas++;
	}
	dp[0][0]=dp[1][1]=cbn[0][0]=per[0][0]=1;
	for (i=2; i<=n; i++)
		for (j=1; j<=i; j++) dp[i][j]=(dp[i-1][j-1]+(ll)dp[i-1][j]*(i-1))%mod;
	for (i=1; i<=n; i++)
		for (j=cbn[i][0]=1; j<=i; j++) cbn[i][j]=(cbn[i-1][j-1]+cbn[i-1][j])%mod;
	for (i=1; i<=n; i++)
		for (j=per[i][0]=1; j<=i; j++) per[i][j]=(ll)per[i][j-1]*(i-j+1)%mod;
	work(f,cnt[0]); work(g,cnt[1]);
	for (i=0; i<=n; i++)
		for (j=0; j<=i; j++) h[i]=(h[i]+(ll)f[j]*g[i-j])%mod;
	for (i=0; i<=n; i++){
		for (j=0; j<=i; j++) ans[i]=(ans[i]+(ll)dp[blk][j]*h[i-j])%mod;
		ans[i]=(ll)ans[i]*per[blk][blk]%mod;
	}
	for (i=0; i<n; i++) printf("%d%c",(n-i-bas>=0)?ans[n-i-bas]:0,(i+1<n)?' ':'\n');
	return 0;
}