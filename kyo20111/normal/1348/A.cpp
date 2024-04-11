#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll a = 0, b = 0;
        for(int i=n/2;i<=n-1;i++) a += 1ll<<i;
        for(int i=1;i<=n/2-1;i++) b += 1ll<<i;
        b += 1ll<<n;
        cout << abs(b - a) << '\n';
    }
}