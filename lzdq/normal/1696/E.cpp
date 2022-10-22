#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=4e5+5,mod=1e9+7;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int n;
ll fac[MAXN],inv[MAXN];
ll C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int ans;
int main(){
	n=4e5;
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=Fstpw(fac[n],mod-2);
	for(int i=n; i; i--)
		inv[i-1]=inv[i]*i%mod;
	scanf("%d",&n);
	for(int i=0; i<=n; i++){
		int a; scanf("%d",&a);
		ans=(ans+C(i+a,i+1))%mod;
	}
	printf("%d\n",ans);
	return 0;
}