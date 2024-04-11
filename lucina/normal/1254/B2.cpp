#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
int const nax = 1e6 + 10;
int a[nax], n;
ll ch(ll x){
    ll cur = 0, res = 0;
    for(int i = 1 ;i <= n; i++){
        cur += a[i];
        cur %= x;
        res += min(cur, x - cur);
    }
    return res;
}

int main(){
    scanf("%d", &n);
    ll sum = 0;
    for(int i = 1 ;i <= n; i ++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    ll ans = 2e18;
    if(sum == 1){
        return !printf("-1");
    }
    for(ll i = 2 ; i * i <= sum; i ++){
        if(sum % i == 0)
            ans = min(ans, ch(i));
        while(sum % i == 0)
            sum /= i;
    }
    if(sum != 1) ans = min(ans, ch(sum));
    printf("%lld\n", ans);
}