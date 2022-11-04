#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll m = 180 * (n-2);
        cout << ((90 * n) % (180 * n - m) == 0?"YES":"NO") << '\n';
    }
}