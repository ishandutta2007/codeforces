#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
long long n;
int t;
long long k;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%lld %lld",&n,&k);
        if(n<62 && (k>(1ll<<(n-1)))) {
            printf("-1\n");
        }
        else {
            for(long long i=1;i<=n;i++) {
                if(n-i>61) {
                    printf("%lld ",i);
                }
                else {
                    long long c=(n-i);
                    if(k==(1ll<<c)) {
                        for(long long j=n;j>=i;j--) {
                            printf("%lld ",j);
                        }
                        break;
                    }
                    else {
                       c=n-i-1;
                       long long l=i;
                       while(k>(1ll<<c)) {
                            k-=(1ll<<c);
                            c--;
                            l++;
                       }
                       for(long long j=l;j>=i;j--) {
                            printf("%lld ",j);
                       }
                       i=l;
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}