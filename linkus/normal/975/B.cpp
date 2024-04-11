#include <bits/stdc++.h>
typedef int64_t ll;
#define e1 first
#define e2 second
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll a[14];
    ll o[14];
    for(auto &i: o){
        cin >> i;
    }
    ll ans = 0;
    for(int i = 0; i < 14; ++i){
        memcpy(a,o,sizeof a);
        ll cr = 0;
        ll off = a[i]/14;
        ll l = a[i]%14;
        a[i] = 0;
        for(int x = i+1; x < 14; ++x){
            if(!l) break;
            --l;
            ++a[x];
        }
        for(int x = 0; l; --l,++x){
            ++a[x];
        }
        for(int x = 0; x < 14; ++x){
            a[x] += off;
            if(a[x] % 2 == 0)
                cr += a[x];
        }
        ans = max(ans,cr);
    }
    cout << ans << '\n';
}