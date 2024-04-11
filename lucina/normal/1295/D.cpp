#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long ;

int main(){
    int T;
    for(cin >> T; T -- ; ){
        ll m, a;
        scanf("%lld %lld", &a, &m);
        ll g = __gcd(a, m);
        ll p = a / g, q = m / g;
        ll c = q;
        vector<ll> pr;
        for(ll i = 2 ; i * i <= c ; i ++){
            if(c % i == 0){
                pr.emplace_back(i);
                while(c % i == 0)
                    c /= i;
            }
        }
        if(c > 1) pr.emplace_back(c);
        ll res = q;
        for(ll it : pr){
            res /= it;
            res *= (it - 1);
        }
        printf("%lld\n", res);
    }
}
/*
    Good Luck
        -Lucina
*/