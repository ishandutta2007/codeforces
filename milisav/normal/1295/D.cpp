#include<bits/stdc++.h>
using namespace std;
long long fi(long long t) {
    if(t==1) {
        return 0;
    }
    long long rt=1;
    for(long long i=2;i*i<=t;i++) {
        if(t%i==0) {
            long long p=1;
            while(t%i==0) {
                t/=i;
                p*=i;
            }
            rt=rt*(p-p/i);
        }
    }
    if(t!=1) rt*=(t-1);
    return rt;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        long long a,m;
        scanf("%lld %lld",&a,&m);
        long long g=__gcd(a,m);
        long long q=m/g;
        printf("%lld\n",fi(q));
    }
    return 0;
}