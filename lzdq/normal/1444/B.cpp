#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5,Mod=998244353;
int n,a[MAXN];
ll fac[MAXN],ans;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%Mod;
		b>>=1;
		a=a*a%Mod;
	}
	return res;
}
int main(){
	scanf("%d",&n);
	n*=2;
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
		if(i<=n/2) ans-=a[i];
		else ans+=a[i];
	ans%=Mod;
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%Mod;
	ll a=Fstpw(fac[n/2],Mod-2);
	ans=ans*fac[n]%Mod*a%Mod*a%Mod;
	printf("%lld\n",ans);
	//ans=ans*C(n,n/2)%Mod;
	return 0;
}