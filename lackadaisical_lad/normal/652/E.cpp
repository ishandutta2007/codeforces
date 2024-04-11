#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// const int MOD = 1e9 + 7;
const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N=300010,M=MOD;
int n,m,a,b,dfn[N],low[N],inx,id[N],scc;
vector<int> gr[N],ans[N];
bool ins[N];
stack<int> inScc;

void tarjan(int v,int p=-1){ // bridge bcc
    bool pp=0;
    inScc.push(v);
    low[v]=dfn[v]=++inx;
    for(auto i:gr[v]){
        if(i!=p||pp){
            if(!dfn[i]){
                tarjan(i,v);
                low[v]=min(low[v],low[i]);
            }
            else low[v]=min(low[v],dfn[i]); //works with min(low[v],low[i])
        }
        else pp=1;
    }
    if(low[v]==dfn[v]){
        while(inScc.top()!=v){
            id[inScc.top()]=scc;
            inScc.pop();
        }
        id[v]=scc++; inScc.pop();
    }
}

void solve() {
    cin >> n >> m;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        a--, b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
        mp[{a, b}] = mp[{b, a}] = x;
    }
    for (int i = 0; i < n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    vector<int> good(scc);
    vector<vector<int>> g(scc);
    map<pair<int, int>, int> kek;
    for (int i = 0; i < n; i++) {
        for (int j : gr[i]) {
            if (id[i] == id[j] && mp[{i, j}]) {
                good[id[i]] = 1;
            }
            if (id[i] != id[j]) {
                g[id[i]].push_back(id[j]);
                kek[{id[i], id[j]}] |= mp[{i, j}];
            }
        }
    }
    int s, t;
    cin >> s >> t;
    s--, t--;
    vector<int> used(scc);
    int ans = 0;
    function<void(int, int)> dfs = [&](int v, int ok) {
        used[v] = 1;
        ok |= good[v];
        if (v == id[t]) {
            ans = ok;
        }
        for (int u : g[v]) {
            if (!used[u]) {
                dfs(u, ok | kek[{v, u}]);
            }
        }
    };
    dfs(id[s], 0);
    cout << (ans ? "YES\n" : "NO\n");
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}