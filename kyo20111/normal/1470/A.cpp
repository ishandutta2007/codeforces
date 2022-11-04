#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll k[300300], c[300300];

void solve_tc(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> k[i];
    for(int i=1;i<=m;i++) cin >> c[i];
    sort(k+1, k+1+n);
    
    ll ans = 0;
    for(int i=1,j=1,l=1;i<=n;i++){
        if(j > k[i] || c[k[l]] < c[j]){
            ans += c[k[l++]];
        }else{
            ans += c[j++];
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc = 1;
    cin >> tc;

    while(tc--){
        solve_tc();
        cout << "\n";
    }
}