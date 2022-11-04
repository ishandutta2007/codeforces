#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, p[200200], cnt[200200], child[200200];
vector<int> v[200200];

void dfs(int u, int par){
    p[u] = par;
    for(auto x : v[u]) if(x != par) dfs(x, u);
}

void solve(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) v[i].clear(), p[i] = 0;

    for(int i=1;i<n;i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
    }

    dfs(1, 0);

    for(int i=1;i<=n;i++) cnt[i] = child[i] = 0;
    for(int i=1;i<=n;i++) cnt[p[i]]++;
    for(int i=1;i<=n;i++) if(!cnt[i]) child[p[i]]++;

    queue<int> q;
    for(int i=2;i<=n;i++) if(cnt[i] && cnt[i] == child[i]) q.push(i);

    int ans = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        ans += cnt[u]-1;

        int x = p[u];
        cnt[x]--;

        if(x != 1){
            if(cnt[x] == 0){
                if(++child[p[x]] == cnt[p[x]] && p[x] != 1) q.push(p[x]);
            }else{
                if(cnt[x] == child[x]) q.push(x);
            }
        }
    }

    cout << max(0, cnt[1]-1) + ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}