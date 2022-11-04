#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int tc;
ll n, r;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> n >> r;
        ll k = min(n - 1, r);
        cout << k * (k+1) / 2 + (n <= r ? 1 : 0) << '\n';
    }
}