#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[100100];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1, a+1+n);

    ll ans = 0, sum = 0;

    for(int i=1;i<=n;i++){
        ans += a[i]-a[i-1];

        ans -= 1ll * (i-1) * a[i] - sum;
        sum += a[i];
    }
    
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}