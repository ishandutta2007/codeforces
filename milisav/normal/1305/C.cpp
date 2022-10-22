#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
long long c[maxn];
long long n,m;
long long a[maxn];
int main() {
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%lld",&a[i]);
        c[a[i]%m]++;
    }
    for(int i=0;i<m;i++) {
        if(c[i]>1) {
            printf("0");
            return 0;
        }
        c[i]=0;
    }
    long long p=1;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            p=(p*abs(a[i]-a[j]))%m;
        }
    }
    printf("%lld",p);
    return 0;
}