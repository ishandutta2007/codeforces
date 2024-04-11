#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,mod=998244353,G=3,invG=(mod+1)/3;
int n,k;
int prm[MAXN],mu[MAXN],pdv[MAXN];
bool nop[MAXN];
ll fac[MAXN],inv[MAXN];
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int f[MAXN],g[MAXN];
int s[MAXN];
bool vis[MAXN];
void Stir(int n){
	g[0]=0;
	g[1]=1;
	for(int i=2; i<=n; i++)
		if(nop[i]) g[i]=1ll*g[pdv[i]]*g[i/pdv[i]]%mod;
		else g[i]=Fstpw(i,n);
	int sum=0,k=min(::k,n);
	for(int i=1; i<=k; i++)
		sum=(sum+g[i]*inv[i]%mod*f[k-i])%mod;
	vis[n]=1;
	s[n]=sum;
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&k);
	if(k==1) return puts("1"),0;
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=Fstpw(fac[n],mod-2);
	for(int i=n; i; i--)
		inv[i-1]=inv[i]*i%mod;
	mu[1]=1;
	for(int i=2; i<=n; i++){
		if(!nop[i]) prm[++*prm]=i,mu[i]=-1;
		for(int j=1; j<=*prm&&i*prm[j]<=n; j++){
			nop[i*prm[j]]=1;
			pdv[i*prm[j]]=prm[j];
			if(i%prm[j]==0) break;
			mu[i*prm[j]]=-mu[i];
		}
	}
	for(int i=0; i<=n; i++)
		f[i]=i&1?mod-inv[i]:inv[i];
	for(int i=1; i<=n; i++)
		f[i]=(f[i]+f[i-1])%mod;
	for(int i=1,t=-1; i<=n; i++){
		int _t=(n+i-1)/i;
		if(_t!=t) Stir(t=_t);
	}
	//for(int i=1; i<=n; i++) if(vis[i]) printf("%d s %d\n",i,s[i]);
	for(int i=1; i<=n; i++)
		if(vis[i]) for(int j=2; j<=i; j++)
			s[i]=(s[i]-s[(i+j-1)/j]+mod)%mod;
	printf("%d\n",s[n]);
	return 0;
}