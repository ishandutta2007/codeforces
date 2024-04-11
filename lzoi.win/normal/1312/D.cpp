#include<cstdio>
const int MAXN=2e5+5,Mod=998244353;
typedef long long ll;
int n,m;
int fac[MAXN],inv[MAXN];
int FstPow(int x,int k){
    ll res=1;
    while(k){
        if(k&1) res=res*x%Mod;
		k/=2;
        x=1ll*x*x%Mod;
    }
    return res;
}
inline int C(int x,int y){
	if(x<y||y<0) return 0;
	int t=1ll*fac[x]*inv[y]%Mod;
	return 1ll*t*inv[x-y]%Mod;
}
ll ans;
int main(){
    fac[0]=inv[0]=1;
    for(int i=1;i<MAXN;i++)
		fac[i]=1ll*fac[i-1]*i%Mod;
	inv[MAXN-1]=FstPow(fac[MAXN-1],Mod-2);
	for(int i=MAXN-1;i>0;i--)
		inv[i-1]=1ll*inv[i]*i%Mod;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++){
        ll sum=(C(m-1,n-2)-C(i-1,n-2)+Mod)%Mod;
        ans=(ans+sum*(FstPow(2,n-1)-2ll*FstPow(2,n-3)%Mod+Mod)%Mod)%Mod;
    }
	ans=ans*FstPow(2,Mod-2)%Mod;
    printf("%I64d\n",ans);
    return 0;
}