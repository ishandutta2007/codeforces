#include<bits/stdc++.h>
using namespace std;
long long a[4];
int t;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%lld %lld %lld %lld",&a[0],&a[1],&a[2],&a[3]);
        sort(a,a+4);
        printf("%lld\n",a[0]*a[2]);
    }
    return 0;
}