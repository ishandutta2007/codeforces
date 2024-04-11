#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
ll calc(ll a, ll b, ll c){
    return abs(a - b) + abs(b - c) + abs(a - c);
}

ll solve(){
    ll a, b, c;
    ll res = 1e18;
    cin >> a >> b >> c;
    for(int i = -1 ;i  <= 1 ; i ++){
        for(int j = -1 ;j <= 1 ;j ++){
            for(int k = -1 ; k <= 1 ; k ++){
                res = min(res, calc(a + i ,  b + j , c + k));
            }
        }
    }
    return res;
}


int main(){
    int q;
    for(cin >> q; q -- ; ){
        printf("%lld\n", solve());
    }

}