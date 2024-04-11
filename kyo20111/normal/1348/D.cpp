#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        ll k = n, b = 0;
        vector<ll> v;

        while(1){
            if(k <= (1ll << b)){
                v.push_back(k);
                break;
            }
            v.push_back(1ll << b);
            k -= (1ll << b);
            b++;
        }

        int l = v.size()-1;
        if(v[l-1] > v[l]){
            ll s = 0;
            for(int i=0;i<l-1;i++) s += v[i];
            ll val = n - s;
            v[l-1] = val/2;
            v[l] = val - (val/2);
        }

        printf("%d\n",v.size()-1);
        for(int i=1;i<v.size();i++) printf("%lld ",v[i]-v[i-1]);
        puts("");
    }
}