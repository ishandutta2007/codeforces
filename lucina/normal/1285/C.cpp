#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll x;
vector<ll> a;
pair<ll, ll> ans;

int main(){
    cin >> x;
    ll c = x;
    ans = {1LL, c};
    for(ll i = 2 ; i * i <= x ;i ++){
        if(x % i ==0){
            if(__gcd(i , x / i) > 1) continue;
            if(max(x / i , i) < max(ans.first, ans.second)){
                ans = {i, x / i};
            }
        }
    }
    printf("%lld %lld\n", ans.first, ans.second);
}