#include<bits/stdc++.h>
using namespace std;
int n,m;
long long mod=1e9+7;
long long step(long long a,long long b) {
    if(b==0) return 1ll;
    if(b&1) return (a*step(a,b-1ll))%mod;
    else return step((a*a)%mod,b>>1ll);
}
long long inv(long long a) {
    return step(a,mod-2);
}
long long fact[600000];
long long invfact[600000];
long long ans=0;
long long nad(long long x,long long y) {
    return (((fact[x]*invfact[y])%mod)*invfact[x-y])%mod;
}
int main() {
    scanf("%d %d",&n,&m);
    fact[0]=invfact[0]=1;
    for(int i=1;i<=2*(n+m);i++) {
        fact[i]=(i*fact[i-1])%mod;
        invfact[i]=inv(fact[i]);
    }
    for(int i=1;2*i<=m;i++) {
        ans=(ans+2*nad(m-i,i))%mod;
    }
    for(int i=0;2*i<=n;i++) {
        ans=(ans+2*nad(n-i,i))%mod;
    }
    printf("%lld",ans);
    return 0;

}