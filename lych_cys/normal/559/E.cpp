#include<bits/stdc++.h>
#define N 305
using namespace std;

int n,cnt,tot,a[N],b[N],c[N],lf[N],rg[N],p[N],q[N],dp[N][N][N];
void up(int &x,int y){ if (x<y) x=y; }
bool cmp(const int &x,const int &y){ return a[x]<a[y]; }
int main(){
	scanf("%d",&n);
	int i,j,k;
	for (i=1; i<=n; i++){
		scanf("%d%d",&a[i],&b[i]);
		c[++cnt]=a[i]-b[i]; c[++cnt]=a[i]; c[++cnt]=a[i]+b[i];
	}
	for (i=1; i<=n; i++) q[i]=i;
	sort(q+1,q+n+1,cmp);
	for (i=1; i<=n; i++){
		lf[i]=a[q[i]]; rg[i]=b[q[i]];
	}
	for (i=1; i<=n; i++){ a[i]=lf[i]; b[i]=rg[i]; }
	sort(c+1,c+cnt+1);
	for (i=2,tot=1; i<=cnt; i++)
		if (c[i]!=c[tot]) c[++tot]=c[i];
	for (i=1; i<=n; i++)
		for (j=1; j<=tot; j++){
			if (a[i]-b[i]==c[j]) lf[i]=j;
			if (a[i]==c[j]) p[i]=j;
			if (a[i]+b[i]==c[j]) rg[i]=j;
		}
	for (i=1; i<=n; i++){
		for (j=1; j<=tot; j++)
			for (k=j; k<=tot; k++){
				up(dp[i][j][max(rg[i],k)],dp[i-1][j][k]+max(0,c[rg[i]]-c[k]));
				if (lf[i]<=j) up(dp[i][(lf[i]<=j)?0:j][max(p[i],k)],dp[i-1][j][k]+max(0,c[p[i]]-c[k]));
			}
		for (j=1; j<=tot; j++){
			if (j<p[i]){
				up(dp[i][0][rg[i]],dp[i-1][0][j]+c[rg[i]]-c[p[i]]);
				for (k=j; k<p[i]; k++)
					up(dp[i][k][rg[i]],dp[i-1][0][j]+c[rg[i]]-c[k]);
			} else up(dp[i][0][max(rg[i],j)],dp[i-1][0][j]+max(0,c[rg[i]]-c[j]));
			up(dp[i][0][max(p[i],j)],dp[i-1][0][j]+max(0,c[p[i]]-c[max(j,lf[i])]));
			for (k=j; k<lf[i]; k++) up(dp[i][k][max(p[i],j)],dp[i-1][0][j]+c[p[i]]-c[k]);
		}
	}
	int ans=0;
	for (i=1; i<=tot; i++) ans=max(ans,dp[n][0][i]);
	printf("%d\n",ans);
	return 0;
}