#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long step(long long a,long long b) {
    if(b==0ll) return 1ll;
    if(b&1ll) return (a*step(a,b-1ll))%mod;
    else return step((a*a)%mod,b>>1ll);
}
long long inverse(long long a) {
    return step(a,mod-2);
}
int n,k;
int h[300000];
int a[300000];
int m;
long long fact[500000];
long long invfact[500000];
long long binomial(long long x,long long y) {
    return (fact[x]*((invfact[y]*invfact[x-y])%mod))%mod;
}
int main() {
    scanf("%d %d",&n,&k);
    fact[0]=invfact[0]=1;
    for(int i=0;i<n;i++) {
        fact[i+1]=(fact[i]*(i+1))%mod;
        invfact[i+1]=inverse(fact[i+1]);
        scanf("%d",&h[i]);
    }
    int md=n-1;
    while(md>0 && h[md]==h[md-1]) md--;
    if(md==0) {
        printf("0");
        return 0;
    }
    for(int i=0;i<n;i++) a[i]=h[(md+i)%n];
    m=1;
    for(int i=1;i<n;i++) {
        if(a[i]!=a[i-1]) m++;
    }
    long long t=step(k,(n-m));
    long long ans=0;
    for(int i=0;i<=m;i++) {
        long long d=0;
        if((m-i)%2==0) d=((step(2,m-i)-binomial(m-i,(m-i)/2)+mod)*inverse(2))%mod;
        else d=step(2,m-i-1);
        ans=(ans+(t*(d*((binomial(m,i)*step(k-2,i))%mod)%mod))%mod)%mod;
    }
    printf("%lld",ans);
    return 0;
}