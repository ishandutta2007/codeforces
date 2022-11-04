#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll w[100100];
vector<int> v[100100];

void solve_tc(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> w[i];

    for(int i=1;i<=n;i++) v[i].clear();
    
    for(int i=1;i<n;i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
    }

    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<ll> pq;
    for(int i=1;i<=n;i++) for(int j=1;j<=v[i].size()-1;j++) pq.push(w[i]);

    ll ans = 0;
    for(int i=1;i<=n;i++) ans += w[i];

    cout << ans << " ";
    for(int i=2;i<n;i++){
        if(!pq.empty()) ans += pq.top(), pq.pop();
        cout << ans << " ";
    }
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