#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// vertex cactus
// identify cycles
// cost is xor of all W, minus xor of costs for a chosen edge from each cycle
// let c[k] = number of ways to get k
// c[k] = sum_{i xor j = k} a[i] * b[j]
// O(cycles * W * log W) time

const int M = 1e9 + 7, M2 = 1000000411, Winv = 742744451, Winv2 = 182472304;

void fst(vi& a, bool inv) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			int &u = a[j], &v = a[j + step];
            // # mod by 1e9 + 7
            tie(u, v) = pii(u + v, u - v);
            u %= M;
            v %= M;
		}
	}
	if (inv) for (int& x : a) {
        x = (1LL * x * Winv) % M;
    }
}
void fst2(vi& a, bool inv) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			int &u = a[j], &v = a[j + step];
            // # mod by 1e9 + 7
            tie(u, v) = pii(u + v, u - v);
            u %= M2;
            v %= M2;
		}
	}
	if (inv) for (int& x : a) {
        x = (1LL * x * Winv2) % M2;
    }
}
// vi conv(vi a, vi b) {
// 	fst(a, 0); fst(b, 0);
// 	rep(i,0,sz(a)) a[i] *= b[i];
// 	fst(a, 1); return a;
// }

const int N = 1e5 + 50, W = (1 << 17);
int n, m, u[N], v[N], w[N], dsu[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

using edge = pii;
bool vis[N];
int tin[N], tout[N], t = 0;
edge par[N];
vector<edge> adj[N];

void dfs(int x) {
    vis[x] = true;
    tin[x] = t++;
    for(edge e : adj[x]) {
        int w, y;
        tie(w, y) = e;
        if(!vis[y]) {
            par[y] = {w, x};
            dfs(y);
        }
    }
    tout[x] = t++;
}

bool anc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vi e;
    int ww = 0;
    fill(dsu, dsu + N, -1);
    rep(i, 0, m) {
        cin >> u[i] >> v[i] >> w[i];
        ww ^= w[i];
        if(trace(u[i]) != trace(v[i])) {
            join(u[i], v[i]);
            adj[u[i]].emplace_back(w[i], v[i]);
            adj[v[i]].emplace_back(w[i], u[i]);
        }else {
            e.push_back(i);
        }
    }
    par[1] = {0, 1};

    dfs(1);
    vi a(W, 0);
    vi a2(W, 0);
    a[0] = 1;
    a2[0] = 1;
    fst(a, false);
    fst2(a2, false);
    for(int i : e) {
        int x = u[i], y = v[i];
        vi b(W, 0);
        b[w[i]]++;
        while(!anc(x, y)) {
            b[par[x].first]++;
            x = par[x].second;
        }
        while(y != x) {
            b[par[y].first]++;
            y = par[y].second;
        }
        vi b2(all(b));
        fst(b, false);
        fst2(b2, false);
        rep(i, 0, W) {
            a[i] = (1LL * a[i] * b[i]) % M;
            a2[i] = (1LL * a2[i] * b2[i]) % M2;
        }
    }
    fst(a, true);
    fst(a2, true);
    int best = W + 1, ans = 0;
    rep(i, 0, W) {
        if((a[i] != 0 || a2[i] != 0) && (ww ^ i) < best) {
            best = (ww ^ i);
            ans = a[i];
        }
    }
    ans = (ans % M + M) % M;
    cout << best << ' ' << ans << '\n';
}