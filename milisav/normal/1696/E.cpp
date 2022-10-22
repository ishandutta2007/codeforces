#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
long long mod=1000000007;
long long step(long long a,long long b) {
    if(b==0) return 1;
    if(b&1ll) return (a*step(a,b-1))%mod;
    else return step((a*a)%mod,b/2);
}
long long inverse(long long a) {
    return step(a,mod-2);
}
long long fact[maxn];
long long invfact[maxn];
long long binom(long long n,long long k) {
    if(k<0 || k>n) return 0;
    return (((fact[n]*invfact[k])%mod)*invfact[n-k])%mod;
}

int n;
int a[maxn];

int main() {
    fact[0]=invfact[0]=1;
    for(int i=1;i<maxn;i++) {
        fact[i]=(fact[i-1]*i)%mod;
        invfact[i]=(invfact[i-1]*inverse(i))%mod;
    }
    scanf("%d",&n);
    long long ans=0;
    for(int i=0;i<=n;i++) {
        scanf("%d",&a[i]);
        ans=(ans+binom(i+a[i],i+1))%mod;
    }
    printf("%lld\n",ans);
    return 0;
}