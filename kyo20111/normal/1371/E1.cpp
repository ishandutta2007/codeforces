#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, p, a[2020];
vector<ll> ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> p;
    for(ll i=1;i<=n;i++) cin >> a[i];
    sort(a+1, a+1+n);
    
    for(ll i=a[1];i<=a[n];i++){
        ll l = 1, r = 1, u = i, s = 1;
        while(r < n && u >= a[r+1]) r++;
        // cout << i << '\n';
        while(l <= r){
            // cout << l << ' ' << r << '\n';
            s = s * (r - l + 1) % p;
            l++, u++;
            while(r < n && u >= a[r+1]) r++;
        }
        if(l > n && s != 0){
            ans.push_back(i);
        }
    }

    cout << ans.size() << '\n';
    for(auto x : ans) cout << x << ' ';
}