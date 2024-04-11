#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, c[30], ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        ll a; cin >> a;
        for(int i=0;i<20;i++) if(a & (1ll<<i)) c[i]++;
    }
    
    while(1){
        ll s = 0;
        for(int i=0;i<20;i++) if(c[i]) s += 1ll << i, c[i]--;
        if(!s) break;
        ans += s * s;
    }

    cout << ans;
}