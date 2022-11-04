#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;


int main(){
    scanf("%lld %lld",&n,&m);

    if(!n && !m) return !printf("0");
    if(n > m) return !printf("-1");
    if(n == m) return !printf("1\n%lld",n);

    if((m - n) % 2) return !printf("-1");

    ll a = 0;
    ll g = m - n;
    for(int b = 59; b > 0; b--){
        ll k = 1ll << b;
        if(g >= k){
            g -= k;
            a |= k/2;
        }
    }

    if((n & a) == 0){
        printf("2\n%lld %lld",n|a,a);
    }else{
        printf("3\n%lld %lld %lld",n,a,a);
    }
}