#include <bits/stdc++.h>
#define maxn 2000005
#define ll long long
const int mod=1e9+7;
int prime[maxn],mu[maxn],vis[maxn],pw[maxn],g[maxn],n,k,tl=0;

void get_Mu(){
	mu[1]=1;
	for(int i=2;i<=k;++i){
		if (!vis[i]){prime[++tl]=i;mu[i]=mod-1;}
		for(int j=1;j<=tl&&i*prime[j]<=k;++j){
			vis[i*prime[j]]=1;
			if (i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}mu[i*prime[j]]=(mod-mu[i])%mod;
		}
	}
}int qpow(int a,int b){
	if (b==0)return 1;
	int d=qpow(a,b>>1);d=(ll)d*d%mod;
	if (b&1)d=(ll)d*a%mod;
	return d;
}

int main(){
	scanf("%d%d",&n,&k);
	get_Mu();
	for(int i=1;i<=k;++i)pw[i]=qpow(i,n);
	for(int i=1;i<=k;++i)
		for(int j=i;j<=k;j+=i)
			g[j]=(g[j]+(ll)mu[i]*(pw[j/i]-pw[j/i-1]+mod))%mod;
	int ans=0;
	for(int i=1;i<=k;++i){
		g[i]=(g[i]+g[i-1])%mod;
	//	g[i]=0;
	//	for(int d=1;d<=i;++d)g[i]=(g[i]+(ll)mu[d]*pw[i/d])%mod;
		//printf("%d ",g[i]);
		ans=(ans+(g[i]^i))%mod;
	}printf("%d",ans);
	return 0;
}