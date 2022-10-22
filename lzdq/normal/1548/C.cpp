#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=3e6+5,mod=1e9+7;
int n,q;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int fac[MAXN],inv[MAXN];
ll C(int n,int m){
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int f[MAXN][2];
int main(){
	scanf("%d%d",&n,&q);
	fac[0]=1;
	for(int i=1; i<=n*3; i++)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[n*3]=Fstpw(fac[n*3],mod-2);
	for(int i=n*3; i; i--)
		inv[i-1]=1ll*inv[i]*i%mod;
	f[0][0]=f[0][1]=n;
	for(int i=1; i<n*3; i++){
		f[i][0]=(C(n*3,i+1)-2*f[i-1][0]%mod-f[i-1][1]+mod*2)%mod*(mod+1)/3%mod;
		f[i][1]=(f[i-1][0]+f[i][0])%mod;
	}
	while(q--){
		int x;
		scanf("%d",&x);
		printf("%lld\n",(f[x][0]+C(n*3,x))%mod);
	}
	return 0;
}