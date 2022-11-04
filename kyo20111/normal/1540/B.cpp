#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
int n, sp[10][202], lev[202];
vector<int> v[202];
ll rev[100100], dp[202][202];

ll pw(ll n, ll k){
    ll re = 1, c = n;
    while(k){
        if(k & 1) re = (re * c) % mod;
        k >>= 1, c = (c * c) % mod;
    }
    return re;
}

void dfs(int u, int p){
    sp[0][u] = p, lev[u] = lev[p]+1;
    for(auto x : v[u]) if(x != p) dfs(x, u);
}

int lca(int a, int b){
    if(lev[a] < lev[b]) swap(a, b);
    for(int i=0;i<10;i++) if((1 << i) & (lev[a] - lev[b])) a = sp[i][a];
    if(a == b) return a;
    for(int i=9;i>=0;i--) if(sp[i][a] != sp[i][b]) a = sp[i][a], b = sp[i][b];
    return sp[0][a];
}

ll f(int l, int r){
    if(!l) return 1;
    if(!r) return 0;
    if(dp[l][r]) return dp[l][r];
    return dp[l][r] = (f(l-1, r) * rev[2] + f(l, r-1) * rev[2]) % mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=1;i<=2;i++) rev[i] = pw(i, mod-2);

    cin >> n;
    for(int i=1;i<n;i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
    }

    ll ans = 0;

    for(int s=1;s<=n;s++){
        dfs(s, 0);
        for(int i=1;i<10;i++) for(int j=1;j<=n;j++) sp[i][j] = sp[i-1][sp[i-1][j]];

        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                int k = lca(i, j);
                ans = (ans + f(lev[i]-lev[k], lev[j]-lev[k])) % mod;
            }
        }

    }
    
    cout << ans * pw(n, mod-2) % mod;
}