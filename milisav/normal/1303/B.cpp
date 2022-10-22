#include<bits/stdc++.h>
using namespace std;
long long n,g,b;
int t;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%lld %lld %lld",&n,&g,&b);
        long long m=n/2;
        if(n%2) m++;
        long long r=m/g;
        if(m%g) r++;
        printf("%lld\n",max(n,(r-1)*b+m));
    }
    return 0;
}