#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1000000007;

struct UF{
    int n;
    vector<int> par;
    UF(int n) : n(n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    void join(int a, int b){
        par[find(a)] = find(b);
    }
};


vector<LL> pow2;
void init(){
    pow2.push_back(1);
    for(LL i = 1; i < 700000; i++){
        pow2.push_back((pow2[i-1] * 2) % MOD);
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    LL n, m, k;
    cin >> n >> m >> k;
    init();
    UF uf(n);
    LL ans = pow2[n + k];
    vector<LL> c(n, 0);
    for(LL j = 0; j < n; j++) cin >> c[j];
    vector<pair<LL, pair<int,int> > > r;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        r.push_back({c[u] ^ c[v], {u, v}});
    }
    sort(r.begin(), r.end());
    vector<pair<int,int> > z;
    for(int i = 0; i < r.size(); i++){
        z.push_back(r[i].second);
        if(i + 1 == r.size() || r[i].first != r[i+1].first){
            // process z;
            LL ncc = n;
            for(auto x : z){
                if(uf.find(x.first) != uf.find(x.second)){
                    ncc--;
                    uf.join(x.first, x.second);
                }
            }
            for(auto x : z){
                uf.par[x.first] = x.first;
                uf.par[x.second] = x.second;
            }
            ans -= (pow2[n] - pow2[ncc]);
            ans %= MOD;
            z.clear();
        }
    }
    ans %= MOD;
    if(ans < 0) ans += MOD;
    cout << ans << '\n';
}