#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
long long p[maxn];
long long n,k;
long long mv=0;
long long mod=998244353;
long long w=1;
bool fnd=false;
int main() {
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&p[i]);
    }
    long long cnt=0;
    for(int i=1;i<=n;i++) {
        if(p[i]>n-k) {
            mv+=p[i];
            if(fnd) {
                w*=(cnt+1);
                w=w%mod;
            }
            fnd=true;
            cnt=0;
        }
        else {
            cnt++;
        }
    }
    printf("%lld %lld",mv,w);
    return 0;
}