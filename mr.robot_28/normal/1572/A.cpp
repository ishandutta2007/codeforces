#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
const int mod = 1e9 + 7;
vector <int>  g[N];
int dp[N];
vector <pair <int, int> > vec;
int timer = 0;
int used[N];
bool flag = 0;
void dfs(int v, int p = -1){
    used[v] = 1;
    for(auto to : g[v]){\
        if(used[to] == 1){
            flag = 1;
        }
        if(!used[to]){
            dfs(to, v);
        }
    }
    used[v] = 2;
    vec.push_back({timer++, v});
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
        flag = 0;
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            for(int j = 0; j < k; j++){
                int x;
                cin >> x;
                x--;
                g[i].push_back(x);
            }
        }
        timer = 0;
        vec.clear();
        for(int i = 0; i < n; i++){
            if(!used[i]){
                dfs(i);
            }
        }
        sort(vec.begin(), vec.end());
        int ans = 0;
        for(auto p : vec){
            for(auto to : g[p.Y]){
                dp[p.Y] = max(dp[p.Y], dp[to] + (to > p.Y));
            }
            ans = max(ans, dp[p.Y] + 1);
        }
        if(flag){
            ans = -1;
        }
        cout << ans << "\n";
        for(int i = 0; i < n; i++){
            used[i] = 0;
            g[i].clear();
            dp[i] = 0;
        }
    }
    return 0;
}