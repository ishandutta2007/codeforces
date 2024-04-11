#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[300300], b[300300], c[300300], d[300300], chk[300300];

int dfs(int u){
    if(chk[u]) return 0;
    chk[u] = 1;
    return dfs(c[u]) + 1;
}

void solve(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<int> v(n, 0);
    for(int i=1;i<=n;i++){
        int d = (a[i] <= i ? i-a[i] : n-a[i]+i);
        v[d]++;
    }

    vector<int> ans;
    for(int k=0;k<n;k++) if(v[k] >= n-2*m){
        int cnt = 0;
        for(int i=1;i<=n;i++) b[i] = i;
        rotate(b+1, b+1+(n-k), b+n+1);
        for(int i=1;i<=n;i++) d[b[i]] = i;
        for(int i=1;i<=n;i++) c[i] = d[a[i]], chk[i] = 0;

        // for(int i=1;i<=n;i++) cout << c[i] << " ";
        // cout << "]\n";

        for(int i=1;i<=n;i++) if(!chk[i]){
            cnt += dfs(i)-1;
            // cout << dfs(i)-1 << "\n";
        }
        // cout << k << " " << cnt << "\n";

        if(cnt <= m) ans.push_back(k);
    }


    cout << ans.size() << " ";
    for(auto x : ans) cout << x << " ";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}