#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long fact[300000];
int main() {
    scanf("%lld %lld",&n,&m);
    fact[0]=1;
    for(long long i=1;i<=n;i++) {
        fact[i]=(i*fact[i-1])%m;
    }
    long long ans=0;
    for(long long k=1;k<=n;k++) {
        long long t=((n-k+1)*(n-k+1))%m;
        t=(t*fact[k])%m;
        t=(t*fact[n-k])%m;
        ans=(ans+t)%m;
    }
    printf("%lld",ans);
    return 0;
}