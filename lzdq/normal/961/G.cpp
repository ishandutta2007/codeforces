#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,mod=1e9+7;
int n,k,ans,sum;
ll fac[MAXN];
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++){
		int a;
		scanf("%d",&a);
		sum=(sum+a)%mod;
	}
	fac[0]=1;
	for(int i=1; i<=k; i++)
		fac[i]=fac[i-1]*i%mod;
	if(n==1) ans=1;
	else for(int i=0; i<k; i++)
		ans=(ans+(i&1?mod-1:1)*Fstpw(fac[i],mod-2)%mod*Fstpw(fac[k-i-1],mod-2)%mod*(Fstpw(k-i,n-1)+(n-1)*Fstpw(k-i,n-2)%mod))%mod;
	ans=1ll*ans*sum%mod;
	printf("%d\n",ans);
	return 0;
}