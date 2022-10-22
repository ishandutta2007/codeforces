#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5,Mod=998244353;
int n,k;
int fac[MAXN],inv[MAXN];
int C(int n,int m){
	//printf("ans+=C %d,%d\n",n,m);
	int t=1ll*fac[n]*inv[m]%Mod;
	return 1ll*t*inv[n-m]%Mod;
}
int Fstpw(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=1ll*res*a%Mod;
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return res;
}
int ans;
int main(){
	scanf("%d%d",&n,&k);
	k--;
	fac[0]=inv[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=1ll*fac[i-1]*i%Mod,inv[i]=Fstpw(fac[i],Mod-2);
	for(int i=1; i<=n; i++){
		int t=n/i-1;
		if(t<k) break;
		ans=(ans+C(t,k))%Mod;
	}
	printf("%d\n",ans);
	return 0;
}