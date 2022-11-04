#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll c[1010];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> c[i];

    ll ans = 0;
    for(int i=1;i<=n;i+=2){
        ll sum = 0;
        ll mn = 1e18;

        for(int j=i+1;j<=n;j+=2){
            sum += c[j-1] - c[j];

            ll A = min(mn, c[i]), B = c[j];

            if(sum < 0) B -= abs(sum);
            else A -= abs(sum);

            if(A > 0 && B > 0) ans += min(A, B);
            if(sum < 0) break;
            mn = min(mn, sum+1);
        }
    }

    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; // cin >> tc;
    while(tc--) solve(), cout << "\n";
}