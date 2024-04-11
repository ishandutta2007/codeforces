#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MOD 1000000007
LL powmod(LL a, LL n){
    if(n == 0) return 1;
    if(n % 2) return (a*powmod(a,n-1)) % MOD;
    LL c = powmod(a, n/2);
    return (c*c) % MOD;
}
LL inv(LL a){
    return powmod(a, MOD-2);
}
LL fact[1100000];
LL invfact[1100000];

LL ncr(LL n, LL r){
    if(r < 0 || n < 0) return 0;
    if(n < r) return 0;
    LL a = fact[n];
    a = (a * invfact[r]) % MOD;
    a = (a * invfact[n-r]) % MOD;
    return a;
}
void init(){
    fact[0] = 1;
    invfact[0] = 1;
    LL inv2 = inv(2);
    for(LL i = 1; i < 110000; i++){
        fact[i] = (i*fact[i-1]) % MOD;
        invfact[i] = inv(fact[i]);
    }
}

// call init();

vector<int> edges[110];
vector<LL> dp[110][2];

vector<LL> comp(vector<LL> a, vector<LL> b){
    vector<LL> f(110,0);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; i + j < f.size(); j++){
            f[i+j] += a[i]*b[j];
            f[i+j] %= MOD;
        }
    }
    return f;
}

vector<LL> add(vector<LL> a, vector<LL> b){
    vector<LL> f(110,0);
    for(int i = 0; i < a.size(); i++) f[i] += a[i];
    for(int i = 0; i < b.size(); i++) f[i] += b[i];
    for(int i = 0; i < 110; i++) f[i] %= MOD;
    return f;
}

void solve(LL v, LL p){
    vector<LL> stuff(110,0);
    stuff[0] = 1;
    for(LL a : edges[v]){
        if(a == p) continue;
        solve(a, v);
        stuff = comp(stuff, add(dp[a][0], dp[a][1]) ) ;
    }
    dp[v][0] = stuff;
    vector<LL> r(110,0);
    r[1] = 1;
    dp[v][1] = comp(stuff, r);
    for(LL a : edges[v]){
        if(a == p) continue;
        vector<LL> ans(110,0);
        ans[0] = 1;
        ans = comp(ans, dp[a][1]);
        for(LL b : edges[v]){
            if(b == p) continue;
            if(a == b) continue;
            ans = comp(ans, add(dp[b][0], dp[b][1]) );
        }
        dp[v][1] = add(dp[v][1], ans);
    }
    return;
}

int main(){
    init();

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    solve(0, -1);
    vector<LL> g = dp[0][1];
    for(int i = 1; i <= n; i++){
        g[i] *= powmod(n, i);
        g[i] %= MOD;
        g[i] *= inv(powmod(n, 2));
        g[i] %= MOD;
    }
    vector<LL> ans(n, 0);
    for(LL a = n-1; a >= 0; a--){
        for(LL b = a; b < n; b++){
            LL r = g[n-b] * ncr(b,a);
            r %= MOD;
            if(b%2 == a%2){
                ans[a] += r;
            } else {
                ans[a] -= r;
            }
            ans[a] %= MOD;
        }
        ans[a] %= MOD;
        while(ans[a] < 0) ans[a] += MOD;
    }
    for(LL a = 0; a < n; a++){
        cout << ans[a] << " ";
    }
    cout << endl;
}