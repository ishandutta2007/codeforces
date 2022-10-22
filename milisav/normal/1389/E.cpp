#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        long long m,w,d;
        scanf("%lld %lld %lld",&m,&d,&w);
        w=w/__gcd(w,d-1);
        long long n=min(m,d);
        long long k=n/w;
        long long c=n%w;
        long long ans=(w-c)*k*(k-1)/2+c*(k+1)*k/2;
        printf("%lld\n",ans);
    }
    return 0;
}