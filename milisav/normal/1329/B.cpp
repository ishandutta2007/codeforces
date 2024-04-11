#include<bits/stdc++.h>
using namespace std;
long long a[60][60];
int main() {
    long long t;
    long long n=40;
    scanf("%lld",&t);
    while(t--) {
        long long d, m;
        scanf("%lld %lld",&d,&m);
        a[0][1]=1%m;
        for(long long j=0;j<=n;j++) a[j][0]=1%m;
        for(long long j=1;j<=n;j++) {
            for(long long i=1;i<=n;i++) {
                a[j][i]=(a[j-1][i]+((1ll<<j)%m)*a[j-1][i-1])%m;
            }
        }
        long long l=0;
        while((1ll<<(l+1))<=d) l++;
        long long tot=(d-(1ll<<l)+1)%m;
        long long sum=0;
        long long add=0;
        if(l!=0) {
            for(long long i=0;i<=n;i++) {
                sum=(sum+a[l-1][i])%m;
            }
        }
        else sum=1;
        add=sum-1;
        printf("%lld\n",(m+(add+(tot*sum)%m)%m)%m);
    }
    return 0;
}