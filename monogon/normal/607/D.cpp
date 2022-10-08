
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

const int N = 2e5 + 5, M = 1e9 + 7;

bool vis[N];
int tin[N], tout[N], tinv[N], ti = 0;

void dfs(int x, vector<vi> &g) {
    vis[x] = true;
    tin[x] = ti++;
    tinv[tin[x]] = x;
    for(int y : g[x]) {
        dfs(y, g);
    }
    tout[x] = ti;
}

ll tree[4 * N], lazy[4 * N];

ll get(int i, int l, int r) {
    return (tree[i] * lazy[i]) % M;
}
void prop(int i, int l, int r) {
    tree[i] = get(i, l, r);
    if(l < r) {
        lazy[2 * i + 1] = (lazy[2 * i + 1] * lazy[i]) % M;
        lazy[2 * i + 2] = (lazy[2 * i + 2] * lazy[i]) % M;
    }
    lazy[i] = 1;
}
ll query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return get(i, l, r);
    prop(i, l, r);
    int m = (l + r) / 2;
    return (query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R)) % M;
}

ll query2(int i, int l, int r, int k) {
    if(l == r) return lazy[i];
    prop(i, l, r);
    int m = (l + r) / 2;
    if(k <= m) return query2(2 * i + 1, l, m, k);
    else return query2(2 * i + 2, m + 1, r, k);
}

void upd(int i, int l, int r, int L, int R, ll x) {
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] = (lazy[i] * x) % M;
        return;
    }
    prop(i, l, r);
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = get(2 * i + 1, l, m) + get(2 * i + 2, m + 1, r);
}

void upd2(int i, int l, int r, int k, ll v) {
    if(l == r) {
        tree[i] = v;
        return;
    }
    prop(i, l, r);
    int m = (l + r) / 2;
    if(k <= m) upd2(2 * i + 1, l, m, k, v);
    else upd2(2 * i + 2, m + 1, r, k, v);
    tree[i] = get(2 * i + 1, l, m) + get(2 * i + 2, m + 1, r);
}

ll modpow(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}
ll modinv(ll a) {
    return modpow(a, M - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll v0; int q;
    cin >> v0 >> q;
    vi ty(q), u(q);
    vector<ll> v(q);
    int k = 1;
    vector<vi> g(1);
    vi par(q + 1, -1);
    rep(i, 0, q) {
        cin >> ty[i] >> u[i];
        u[i]--;
        if(ty[i] == 1) {
            cin >> v[i];
            g.emplace_back();
            g[u[i]].push_back(k);
            par[k] = u[i];
            k++;
        }
    }
    dfs(0, g);
    fill(tree, tree + 4 * N, 0);
    fill(lazy, lazy + 4 * N, 1);
    upd2(0, 0, k - 1, 0, v0);
    int si = 1;
    vi S(k, 1);
    rep(i, 0, q) {
        if(ty[i] == 1) {
            ll mul = ((S[u[i]] + 1) * modinv(S[u[i]])) % M;
            upd(0, 0, k - 1, tin[u[i]], tout[u[i]] - 1, mul);
            upd2(0, 0, k - 1, tin[si], v[i]);
            S[u[i]]++;
            si++;
        }else {
            ll num = query(0, 0, k - 1, tin[u[i]], tout[u[i]] - 1);
            ll den = (par[u[i]] == -1 ? 1 : query2(0, 0, k - 1, tin[par[u[i]]]));
            cout << ((num * modinv(den)) % M) << '\n';
        }
    }
}