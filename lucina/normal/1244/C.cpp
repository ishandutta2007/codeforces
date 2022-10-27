#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
using ll = long long ;
ll n,p,w,d;
ll x, y ,z;
void ans(ll a, ll b , ll c){
    printf("%lld %lld %lld\n",a,b,c);
    exit(0);
}

int main(){
    cin >> n >> p >> w >> d;
    ll g = __gcd(w, d);
    if(p % g)return !printf("-1");
    p /= g, w /= g, d /= g;
    ll res = (p - 1) / w + 1;
    if(res > n) return !printf("-1");
    x = res;
    if(w * res == p) ans(x, y ,n - x - y);
    ll cur = p - w * res;
    while(true){
        x --;
        if(x < 0) break;
        cur += w;
        if(cur % d ==0 && x + cur /d <= n){
            ans(x, cur / d, n - x - cur /d);
        }
    }
    printf("-1");
}
/*
    Virtual Round 592
*/