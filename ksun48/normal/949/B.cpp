#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL solve(LL n, LL x){
    LL cn = n;
    LL f = (x-1)/2;
    x -= 2*f;
    cn -= f;
    if(x == 1){
        return 1 + f;
    }
    return 1 + f + solve(cn-1, cn-1);
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    LL n, q;
    cin >> n >> q;
    for(int i = 0; i < q; i++){
        LL x;
        cin >> x;
        cout << solve(n,x) << '\n';
    }
}