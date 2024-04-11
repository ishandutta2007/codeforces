#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int chk[1001001], n, q, a[300300];
vector<int> sosu;

void solve_tc(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    
    map<vector<int>, int> mp;
    for(int i=1;i<=n;i++){
        vector<int> v;
        int A = a[i];
        for(int x : sosu){
            int cnt = 0;
            while(A % x == 0) A /= x, cnt++;
            if(cnt % 2) v.push_back(x);

            if(A == 1) break;
        }
        if(A > 1) v.push_back(A);
        mp[v]++;
    }

    int mx = 0, cnt = 0, cnt2 = 0;
    for(auto [x, y] : mp) mx = max(mx, y);
    for(auto [x, y] : mp){
        if(x.empty() || y % 2 == 0) cnt += y;
    }

    cin >> q;
    while(q--){
        ll w; cin >> w;
        if(w == 0) cout << mx << "\n";
        else cout << max(cnt, mx) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    for(int i=2;i*i<=1000000;i++){
        if(chk[i]) continue;
        sosu.push_back(i);
        for(int j=i+i;j*j<=1000000;j+=i) chk[i] = 1;
    }

    int tc = 1;
    cin >> tc;

    while(tc--){
        solve_tc();
        // cout << "\n";
    }
}