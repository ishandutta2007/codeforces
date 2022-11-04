#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll lb, ll ub){ return uniform_int_distribution<ll>(lb, ub)(rng); }
 
int t, n, m;
ll a[500500], mod1 = 993244853, mod2 = 1000000007;
map<pair<ll, ll>, ll> mp;
vector<int> ad[500500];
vector<ll> v = {500009, 500029, 500041, 500057, 500069};
int main(){
 
    scanf("%d",&t);
    while(t--){
        mp.clear();
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) ad[i].clear();
        for(int i=1;i<=n;i++) scanf("%lld",a+i);
        for(int i=1;i<=m;i++){
            int b, c; scanf("%d %d",&b,&c);
            ad[c].push_back(b);
        }
        int k = randint(0, v.size()-1);
        ll m1 = v[k], m2 = v[(k + randint(1, v.size()-1)) % v.size()];
        
        for(int i=1;i<=n;i++){
            if(ad[i].empty()) continue;
            ll v1 = 0, v2 = 0;
            sort(ad[i].begin(), ad[i].end());
            for(auto c : ad[i]){
                v1 = (v1 * m1 + c) % mod1;
                v2 = (v2 * m2 + c) % mod2;
            }
            mp[{v1, v2}] += a[i];
        }
 
        ll g = 0;
        for(auto it : mp) g = __gcd(it.second, g);
        printf("%lld\n",g);
    }
}