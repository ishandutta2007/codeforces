#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;
ll fac[200200];
ll pw(ll a ,ll x){
    if(!x) return 1;
    ll re = pw(a, x/2) % mod;
    return re * re % mod * (x % 2 ? a : 1) % mod;
}
ll C(ll n, ll k){
    return fac[n] * pw(fac[k], mod-2) % mod * pw(fac[n-k], mod-2) % mod;
}
int n, m;

int main(){
    fac[0] = 1;
    for(int i=1;i<=200000;i++) fac[i] = (fac[i-1] * i) % mod;
    scanf("%d %d",&n,&m);
    printf("%lld",C(m, n-1) * (n-2) % mod * pw(2, n-3) % mod);
}