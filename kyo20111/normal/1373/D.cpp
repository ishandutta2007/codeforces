#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n;
ll a[200200], b[200200];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        ll mx = 0, sum = 0;
        for(int i=1;i<=n;i++) if(i%2) sum += a[i];

        for(int i=1;i<=n/2;i++){
            b[i] = a[i*2] - a[i*2-1] + max(0ll, b[i-1]);
            mx = max(mx, b[i]);
        }

        for(int i=1;i<(n+1)/2;i++){
            b[i] = a[i*2] - a[i*2+1] + max(0ll, b[i-1]);
            // cout << '[' << i*2 << ' ' << i*2+1 << "] : " << a[i*2] - a[i*2+1] << ", ";
            mx = max(mx, b[i]);
        }

        cout << mx + sum << '\n';
    }
}