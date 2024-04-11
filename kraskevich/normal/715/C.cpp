#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct ModularRing {
    ll mod;
    
    ModularRing(ll mod): mod(mod) {
        assert (mod > 0);
    }
    
    ll proper_mod(ll x) {
        x %= mod;
        if (x < 0)
            x += mod;
        return x;
    }
    
    ll get_inverse(ll a) {
        a = proper_mod(a);
        if (a == 0)
            return 0;
        ll x;
        ll y;
        assert(extended_gcd(a, mod, x, y) == 1);
        x = proper_mod(x);
        assert(x * a % mod == 1);
        return x;
    }
    
    ll extended_gcd(ll a, ll b, ll &x, ll &y) {
        if (a == 0) {
            x = 0; 
            y = 1;
            return b;
        }
        ll x1;
        ll y1;
        ll d = extended_gcd(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }
};


struct CentroidDecomposition {
    // These members are generic.
    vector<vector<int>> g;
    vector<bool> deleted;
    vector<int> root;
    vector<int> size;
    vector<int> max_size;
    vector<int> visited;
    
    // These members are problem-specific
    vector<ll> pw;
    vector<ll> inv_pw;
    vector<vector<int>> digit;
    vector<unordered_map<int, ll>> for_root;
    vector<ll> from_lca;
    vector<ll> to_lca;
    vector<int> height;
    ll res{0};
    ll MOD;
    
    CentroidDecomposition(
            // Generic parameters
            const vector<vector<int>>& g,
            // Problem-specific parameters
            const vector<vector<int>>& digit, const vector<ll>& pw, const vector<ll>& inv_pw, ll MOD):
        g(g), deleted(g.size()), root(g.size()), size(g.size()), max_size(g.size()), visited(g.size()),
        // Problem-specific members initialization
        digit(digit), pw(pw), inv_pw(inv_pw), for_root(g.size()), from_lca(g.size()), 
        to_lca(g.size()), height(g.size()), MOD(MOD) {}

    
    // Finds the centroid of the current tree. Fills the vector of visited vertices
    void dfs_pre(int v, int par) {
        visited.push_back(v);
        size[v] = 1;
        max_size[v] = 0;
        for (int to : g[v])
            if (to != par && !deleted[to]) {
                dfs_pre(to, v);
                size[v] += size[to];
                max_size[v] = max(max_size[v], size[to]);
            }
    }
    
    // Computes the root of the current component
    void dfs_root(int v, int cur_root, int par) {
        root[v] = cur_root;
        for (int to : g[v])
            if (to != par && !deleted[to])
                dfs_root(to, cur_root, v);
    }

    // This function is problem-specific
    void dfs_calc(int v, int h, int par, ll cur_from, ll cur_to) {
        from_lca[v] = cur_from;
        to_lca[v] = cur_to;
        height[v] = h;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            ll d = digit[v][i];
            if (to != par && !deleted[to])
                dfs_calc(to, h + 1, v, (cur_from + pw[h] * d) % MOD, (cur_to * 10 +  d) % MOD);
        }
    }
    
    void solve(int start) {
        dfs_pre(start, start);
        vector<int> all = visited;
        visited.clear();
        int v = -1;
        for (int x : all) {
            int rest = max((int)all.size() - size[x], max_size[x]);
            if (2 * rest <= all.size())
                v = x;
        }
        assert (v != -1);
        deleted[v] = true;
        for (int to : g[v])
            if (!deleted[to]) {
                solve(to);
                dfs_root(to, to, to);
            }
        deleted[v] = false;
        
        // Problem-specific code goes here
        dfs_calc(v, 0, v, 0, 0);
        for (int x : all)
            for_root[root[x]].clear();
        map<int, ll> all_from;
        for (int x : all) {
            if (x != v) {
                all_from[from_lca[x]]++;
                for_root[root[x]][from_lca[x]]++;
            }
        }
        for (int x : all) {
            if (v == x)
                continue;
            ll a = -to_lca[x] * inv_pw[height[x]];
            a = (a % MOD + MOD) % MOD;
            res += all_from[a];
            res -= for_root[root[x]][a];
            if (from_lca[x] == 0)
                res++;
            if (to_lca[x] == 0)
                res++;
        }
    } 
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n;
    ll MOD;
    cin >> n >> MOD;
    vector<vector<int>> g(n);
    vector<vector<int>> digit(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        g[a].push_back(b);
        g[b].push_back(a);
        digit[a].push_back(d);
        digit[b].push_back(d);
    }
    ModularRing ring(MOD);
    vector<ll> pw(n, 1 % MOD);
    vector<ll> inv_pw(n);
    for (int i = 0; i < n; i++) {
        if (i > 0)
            pw[i] = pw[i - 1] * 10 % MOD;
        inv_pw[i] = ring.get_inverse(pw[i]);
    }
    CentroidDecomposition decomposition(g, digit, pw, inv_pw, MOD);
    decomposition.solve(0);
    cout << decomposition.res << endl;
}