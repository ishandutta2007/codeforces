#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=5005,mod=998244353;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
ll fac[MAXN],inv[MAXN];
int n,a[MAXN],b[MAXN],c[MAXN];
int f[MAXN],g[MAXN],ans;
int main(){
	n=5000;
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=Fstpw(fac[n],mod-2);
	for(int i=n; i; i--)
		inv[i-1]=inv[i]*i%mod;
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		memset(c,0,sizeof(c));
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),c[a[i]]++;
		for(int i=1; i<=n+1; i++)
			b[i]=lower_bound(a+1,a+n+1,i)-a;
		for(int i=1; i<=n; i++)
			f[i]=b[a[i]]-1;
		for(int i=1; i<n/2; i++){
			memset(g,0,sizeof(g));
			for(int j=1; j<=n; j++)
				if(f[j]) (g[b[a[j]+1]]+=f[j]*(b[a[j]]-2ll*i)%mod)%=mod;
			for(int j=1; j<=n; j++)
				f[j]=(f[j-1]+g[j])%mod;
		}
		ans=0;
		for(int i=1; i<=n; i++)
			ans=(ans+f[i])%mod;
		for(int i=1; i<=n; i++)
			ans=ans*inv[c[i]]%mod;
		printf("%d\n",ans);
	}
	return 0;
}