#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll k, a[200200];

void solve(){
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1, a+1+n);
    ll g = a[2] - a[1];
    for(int i=2;i<n;i++){
        g = __gcd(g, a[i+1] - a[i]);
    }

    cout << (abs(k - a[1]) % g == 0 ? "YES" : "NO");
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while(tc--){
        solve();
        cout << "\n";
    }
}