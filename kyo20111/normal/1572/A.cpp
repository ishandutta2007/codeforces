#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, p[200200];
vector<int> v[200200];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) v[i].clear(), p[i] = 0;

    for(int i=1;i<=n;i++){
        int a; cin >> a;
        while(a--){
            int b; cin >> b;
            p[i]++, v[b].push_back(i);
        }
    }

    priority_queue<int, vector<int>, greater<int>> q[2];
    for(int i=1;i<=n;i++) if(!p[i]) q[0].push(i);

    int ans = 0;
    while(!q[0].empty()){
        while(!q[0].empty()){
            int u = q[0].top(); q[0].pop();
            for(auto x : v[u]) if(--p[x] == 0){
                if(u < x) q[0].push(x);
                else q[1].push(x);
            }
        }

        ans++;
        while(!q[1].empty()) q[0].push(q[1].top()), q[1].pop();
    }

    for(int i=1;i<=n;i++) if(p[i]){
        cout << -1;
        return;
    }

    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}