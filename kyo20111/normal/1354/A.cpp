#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, a, b, c, d;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        if(a <= b){
            printf("%lld\n",b);
            continue;
        }
        if(c <= d){
            printf("-1\n");
            continue;
        }

        ll s = (a - b) / (c - d) + ((b - a) % (c - d) ? 1 : 0);
        printf("%lld\n",b + s * c);
    }
}