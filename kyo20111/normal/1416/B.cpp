#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int tc, n;
ll a[10010], m[10010];
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
 
        ll s = 0;
        for(int i=1;i<=n;i++) s += a[i];
 
        if(s % n){
            cout << "-1\n";
            continue;
        }
 
        s /= n;
 
        vector<tuple<int, int, ll>> ans;
 
        for(int i=2;i<=n;i++){
            ll k = a[i] / i;
            if(a[i] % i) ans.push_back({1, i, i - a[i] % i}), k++;
            ans.push_back({i, 1, k});
        }

        for(int i=2;i<=n;i++) ans.push_back({1, i, s});
 
        cout << ans.size() << "\n";
        for(auto [a, b, c] : ans) cout << a << " " << b << " " << c << "\n";
    }
}