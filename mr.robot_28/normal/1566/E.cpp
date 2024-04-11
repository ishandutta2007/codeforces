#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
const int mod = 1e9 + 7;
vector <int> g[N];
int res;
int dfs(int v, int p = -1){
    int cnt = 0;
    for(auto to : g[v]){
        if(to == p){
            continue;
        }
        cnt += dfs(to, v);
    }
    if(cnt == 0){
        return 1;
    }
    res += cnt - 1;
    return 0;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        res = 0;
        dfs(0);
        cout << res + 1 << "\n";
        for(int i = 0; i < n; i++){
            g[i].clear();
        }
    }
    return 0;
}