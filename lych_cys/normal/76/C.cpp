#include<bits/stdc++.h>
#define N 22
#define M 4194304
using namespace std;

int n,m,tot,bin[25],a[N][N],p[M],dp[M],f[N],mrk[N],sum[M]; char s[200005];
int main(){
	scanf("%d%d%d%s",&n,&m,&tot,s+1);
	int i,j,k;
	bin[0]=1; for (i=1; i<=m; i++) bin[i]=bin[i-1]<<1;
	for (i=0; i<m; i++) scanf("%d",&p[bin[i]]);
	for (i=0; i<m; i++)
		for (j=0; j<m; j++) scanf("%d",&a[i][j]);
	for (i=1; i<=n; i++){
		k=s[i]-'A';
		for (j=0; j<m; j++) if (f[j]){
			if (f[k]>f[j]) continue;
			dp[mrk[j]]+=a[j][k];
			dp[mrk[j]|bin[j]]-=a[j][k]; dp[mrk[j]|bin[k]]-=a[j][k];
			dp[mrk[j]|bin[j]|bin[k]]+=a[j][k];
		}
		f[k]=i; mrk[k]=0;
		for (j=0; j<m; j++) if (j!=k) mrk[j]|=bin[k];
	}
	for (i=0; i<m; i++)
		for (j=1; j<bin[m]; j++) if (j&bin[i]) dp[j]+=dp[j^bin[i]];
	for (i=1; i<bin[m]; i++) sum[i]=sum[i^i&-i]+p[i&-i];
	int tmp=0,ans=0;
	for (i=0; i<m; i++) if (!f[i]) tmp|=bin[i];
	for (i=0; i<bin[m]; i++)
		if (dp[i]+sum[i]<=tot && !(i&tmp) && (i|tmp)!=bin[m]-1) ans++;
	printf("%d\n",ans);
	return 0;
}