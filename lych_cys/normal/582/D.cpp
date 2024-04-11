#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define calc(x) (((ll)(x)*((x)+1)>>1)%mod)
#define N 4005
using namespace std;

int n,len,p,q,dp[N][N][2][2],a[N],b[N],c[N]; char s[N];
int solve(){
	ll tmp=0; int i;
	for (i=len; i; i--){
		tmp=tmp*10+a[i];
		b[i]=tmp/p; tmp%=p;
	}
	while (len>1 && !b[len]) len--;
	memcpy(a,b,sizeof(b));
	return tmp;
}
int main(){
	scanf("%d%d",&p,&q);
	scanf("%s",s+1);
	len=strlen(s+1);
	int i,j,k;
	for (i=1; i<=len; i++) a[i]=s[len-i+1]-'0';
	a[1]++;
	for (i=1; i<=len; i++) if (a[i]>9){
		a[i]-=10; a[i+1]++;
	}
	if (a[len+1]) len++;
	while (a[len]) c[++n]=solve();
	if (q>=n){ puts("0"); return 0; }
	dp[0][0][1][0]=1;
	for (i=1; i<=n; i++)
		for (j=0; j<=i; j++){
			for (k=0; k<2; k++){
				dp[i][j][k][0]=(dp[i-1][j][1][0]*calc((k)?p:c[i])+dp[i-1][j][1][1]*calc((k)?p-1:c[i]-1))%mod;
				dp[i][j][k][1]=((ll)dp[i-1][j-1][1][0]*(calc(p-1)-(!k)*calc(p-c[i]-1)+mod)+dp[i-1][j-1][1][1]*(calc(p)-(!k)*calc(p-c[i])+mod))%mod;
			}
			dp[i][j][0][0]=(dp[i][j][0][0]+(ll)dp[i-1][j][0][0]*(c[i]+1)+(ll)dp[i-1][j][0][1]*c[i])%mod;
			dp[i][j][0][1]=(dp[i][j][0][1]+(ll)dp[i-1][j-1][0][0]*(p-1-c[i])+(ll)dp[i-1][j-1][0][1]*(p-c[i]))%mod;
		}
	int ans=0;
	for (i=q; i<n; i++) ans=(ans+dp[n][i][0][0])%mod;
	printf("%d\n",ans);
	return 0;
}