#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5,mod=1e9+7;
int n,m,k;
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
ll C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int f[MAXN];
int main(){
	//freopen("in1.txt","r",stdin);
	n=1e6;
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=Fstpw(fac[n],mod-2);
	for(int i=n; i; i--)
		inv[i-1]=inv[i]*i%mod;
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1; i<=m; i++)
			f[i]=C(n,i-1);
		for(int i=1; i<=m; i++)
			f[i]=(f[i]+f[i-1])%mod;
		for(int i=1; i<=m; i++)
			f[i]=(f[i]+f[i-1])%mod;
		k=k*Fstpw(mod+1>>1,n-1)%mod*f[m]%mod;
		printf("%d\n",k);
	}
	return 0;
}