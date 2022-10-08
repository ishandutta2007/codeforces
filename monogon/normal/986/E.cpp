
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5 + 5, A = 1e7 + 5, M = 1e9 + 7;
int n, a[N];
vi adj[N];
int prime[A];
vi vec[A];
unordered_map<int, vector<pii>> vec2;
int ti = 0, tin[N], tout[N], par[N][18];

void dfs(int x, int p) {
    par[x][0] = p;
    tin[x] = ti++;
    for(int y : adj[x]) {
        if(y != p) {
            dfs(y, x);
        }
    }
    tout[x] = ti++;
}

bool anc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int lca(int x, int y) {
    if(anc(x, y)) return x;
    for(int l = 17; l >= 0; l--) {
        if(!anc(par[x][l], y)) x = par[x][l];
    }
    return par[x][0];
}

ll modpow(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}
ll modinv(ll a) {
    return modpow(a, M - 2);
}

ll solve(int u, int x) {
    ll ans = 1;
    while(x > 1) {
        int p = prime[x];
        int cnt = 0;
        while(x % p == 0) {
            x /= p;
            cnt++;
        }
        int pp = 1, sum = 0;
        for(int i = 1; i <= cnt; i++) {
            pp *= p;
            pii pa = {tin[u], 1e9};
            auto it = lower_bound(all(vec2[pp]), pa);
            if(it != vec2[pp].begin()) sum += prev(it)->second;
        }
        ans = (ans * modpow(p, sum)) % M;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(p, 2, A) {
        if(prime[p] == 0) {
            for(int i = p; i < A; i += p) {
                prime[i] = p;
            }
        }
    }
    
    cin >> n;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i, 1, n + 1) {
        cin >> a[i];
        int x = a[i];
        while(x > 1) {
            int p = prime[x];
            int cnt = 0;
            while(x % p == 0) {
                x /= p;
                cnt++;
            }
            int pp = 1;
            for(int j = 1; j <= cnt; j++) {
                pp *= p;
                vec[pp].push_back(i);
            }
        }
    }

    dfs(1, 1);
    rep(l, 1, 18) {
        rep(i, 1, n + 1) {
            par[i][l] = par[par[i][l - 1]][l - 1];
        }
    }

    rep(i, 0, A) {
        if(!vec[i].empty()) {
            vec2[i].reserve(2 * sz(vec[i]));
            for(int u : vec[i]) {
                vec2[i].emplace_back(tin[u], 1);
                vec2[i].emplace_back(tout[u], -1);
            }
            sort(all(vec2[i]));
            rep(j, 1, sz(vec2[i])) {
                vec2[i][j] = {vec2[i][j].first, vec2[i][j].second + vec2[i][j - 1].second};
            }
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int u, v, x;
        cin >> u >> v >> x;
        int c = lca(u, v);
        ll val = solve(c, x);
        val = (val * val) % M;
        ll a1 = solve(u, x);
        ll a2 = solve(v, x);
        ll a3 = modinv(val);
        ll a4 = gcd(x, a[c]);
        ll ans = (((a1 * a2) % M) * ((a3 * a4) % M)) % M;
        cout << ans << '\n';
    }
}