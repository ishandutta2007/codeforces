#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,mod=998244353;
int n,m,T,ans,flg;
int a[maxn],f[maxn],pl[maxn],pr[maxn],fac[maxn],nfac[maxn],inv[maxn];
long long sum[maxn],suf[maxn];
string s;
inline int C(int a,int b){
	return a<b? 0:1ll*fac[a]*nfac[b]%mod*nfac[a-b]%mod;
}
int main(){
	fac[0]=fac[1]=nfac[0]=nfac[1]=inv[1]=1;
	for(int i=2;i<maxn;i++)
		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod,nfac[i]=1ll*nfac[i-1]*inv[i]%mod;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
		suf[n+1]=0;
		for(int i=n;i>=1;i--)
			suf[i]=suf[i+1]+a[i];
		for(int i=1,l=n+1,r=n;i<=n;i++){
			while(l>1&&suf[l-1]<=sum[i])
				l--;
			while(r>=1&&suf[r]<sum[i])
				r--;
			pl[i]=l,pr[i]=r;
//			printf("i=%d [%d,%d]\n",i,l,r);
			//l: suf[l]<=sum[i] 
			//r: suf[r]<sum[i]
		}
		int now=1;
		for(int i=1;i<=n;i++){
			int j=i;
			while(j+1<=n&&sum[j+1]==sum[j])
				j++;
			int u=pl[i],v=pr[i];
			if(u<=v&&i<=v){
//				printf("[%d,%d] [%d,%d] now=%d\n",i,j,u,v,now);
				int f=0;
				if(j>=u)
					for(int k=2;k<=v-i+1;k+=2)
						f=(f+C(v-i+1,k))%mod;
				else for(int k=1;k<=j-i+1&&k<=v-u+1;k++)
						f=(f+1ll*C(j-i+1,k)*C(v-u+1,k))%mod;
				now=(now+1ll*now*f)%mod;
			}
			i=j;
		}
		printf("%d\n",now);
		for(int i=1;i<=n;i++)
			f[i]=0;
	}
	return 0;
}