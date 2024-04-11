#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define ull unsigned long long
using namespace std;
const int N = 1e5 + 10;
struct vec {
    ll x, y;
    vec(ll _x = 0, ll _y = 0) {x = _x, y = _y; }
    void rd() {cin >> x >> y; }
    friend vec operator + (const vec a, const vec b) {
        return vec(a.x + b.x, a.y + b.y);
    }
    friend vec operator - (const vec a, const vec b) {
        return vec(a.x - b.x, a.y - b.y);
    }
    friend ll operator * (const vec a, const vec b) {
        return a.x * b.y - a.y * b.x;
    }
    friend bool operator < (const vec a, const vec b) {
        return tie(a.x, a.y) < tie(b.x, b.y);
    }
    void wt() {
        cout << x <<" " << y << endl;
    }
}a[N];
int n, m, siz[N], fa[N], vis[N];
map<int, int> pos[N];
vector<int> e[N], s[N];
int w(int u, int v) {
    if(fa[u] == v) return siz[u];
    if(fa[v] == u) return - siz[v];
    return 0;
}
void dfs(int u) {
    vis[u] = 1;
    siz[u] = 1;
    for(auto v : e[u]) if(!vis[v]) {
        dfs(v);
        fa[v] = u;
        siz[u] += siz[v];
    }
}
const vec o(0, 0);
int cmp(vec vp, vec vq) {
    int tp = (o < vp), tq = (o < vq);
    if(tp != tq) return tp > tq;
    return vp * vq > 0;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v), e[v].emplace_back(u);
    }
    FOR(i, 1, n) a[i].rd();
    dfs(1);
    FOR(u, 1, n) {
        sort(e[u].begin(), e[u].end(), [&](int p, int q) {
            return cmp(a[p] - a[u], a[q] - a[u]);
        });
        FOR(i, 0, sz(e[u]) - 1) pos[u][e[u][i]] = i;
        s[u].resize(sz(e[u]) + 1);
        FOR(i, 0, sz(e[u]) - 1) {
            s[u][i + 1] = s[u][i] + w(u, e[u][i]);
            // cout << s[u][i + 1] << " ";
        }
    }
    int q;
    cin >> q;
    FOR(i, 1, q) {
        int k;
        cin >> k;
        vector<int> id(k);
        FOR(j, 0, k - 1) cin >> id[j];
        ll area = 0, ans = 0;
        FOR(j, 0, k - 1) area += a[id[j]] * a[id[(j + 1) % k]];
        if(area < 0) {
            reverse(id.begin(), id.end());
        }
        FOR(j, 0, k - 1) {
            int u = id[(j + 1) % k];
            int pl = pos[u][id[j]], pr = pos[u][id[(j + 2) % k]];
            if(pl <= pr) {
                ans += s[u][pr] - s[u][pl + 1];
            } else {
                ans += s[u].back() - s[u][pl + 1];
                ans += s[u][pr];
            }
        }
        if(ans <= 0) ans = n + ans;
        cout << ans << "\n";
    }
    return 0;
}