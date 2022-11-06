#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#define ll long long
#define mod 1000000007
#define N 300005
#define M 6000005
using namespace std;

int n,cnt,tot,fst[N],len[M],nxt[M],prm[N],p[N],q[N],tp,inv[N],dp[N],cbn[N];
int main(){
	scanf("%d",&n);
	int i,j,k;
	for (i=2; i<=300000; i++){
		if (!p[i]) prm[++cnt]=p[i]=i;
		for (j=1; j<=cnt && (k=i*prm[j])<=300000; j++){
			p[k]=prm[j];
			if (!(i%prm[j])) break;
		}
	}
	for (i=1; i<=n; i++){
		scanf("%d",&k);
		for (j=0; k>1; k/=p[k])
			if (p[k]==j) len[tot]++; else{
				len[++tot]=1; nxt[tot]=fst[j=p[k]]; fst[j]=tot;
			}
	}
	inv[0]=inv[1]=1;
	for (i=2; i<=n; i++)
		inv[i]=mod-(ll)inv[mod%i]*(mod/i)%mod;
	for (i=cbn[0]=1; i<n; i++)
		cbn[i]=(ll)cbn[i-1]*(n-i)%mod*inv[i]%mod;
	for (i=dp[n]=1; i<n; i++) dp[n]=(dp[n]<<1)%mod;
	dp[n]--;
	for (i=n-1; i; i--)
		dp[i]=(dp[i+1]+(mod-cbn[i]+mod-cbn[i-1])%mod)%mod;
	int ans=0;
	for (i=2; i<=300000; i++) if (p[i]==i && fst[i]){
		for (j=fst[i],tp=0; j; j=nxt[j]) q[++tp]=len[j];
		sort(q+1,q+tp+1);
		for (j=1; j<=tp; j++)
			ans=(ans+(ll)dp[n-tp+j]*q[j])%mod;
	}
	printf("%d\n",ans);
	return 0;
}