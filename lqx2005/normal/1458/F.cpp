#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long i64;
const int N = 2e5 + 10, K = 18;
int n, tot = 0, L2[N];
int anc[K][N], dep[N];
vector<int> g[N];
i64 ans = 0;
void adde(int u, int v) {
    g[u].push_back(v);
}

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    anc[0][u] = fa;
    for(int i = 1; i < K; i++) {
        anc[i][u] = anc[i - 1][anc[i - 1][u]];
    }
    for(int &v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
    }
    return;
}

int jump(int u, int k) {
    for(; k; k -= k & -k) {
        u = anc[L2[k & -k]][u];
    }
    return u;
}

int LCA(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    int d = dep[v] - dep[u];
    v = jump(v, d);
    if(u == v) return u;
    for(int i = K - 1; i >= 0; i--) {
        if(anc[i][u] != anc[i][v]) {
            u = anc[i][u], v = anc[i][v];
        }
    }
    return anc[0][u];
}

int dis(int u, int v) {
    int lca = LCA(u, v);
    return dep[u] + dep[v] - dep[lca] * 2;
}

int walk(int u, int v, int k) {
    int lca = LCA(u, v);
    if(dep[u] - dep[lca] >= k) return jump(u, k);
    k -= dep[u] - dep[lca];
    return jump(v, dep[v] - dep[lca] - k);
}

struct C {
    int u, r;
    C() {u = r = 0; }
    C(int center, int radius) {u = center, r = radius; }
    friend C operator + (C a, C b) {
        if(a.r < b.r) swap(a, b);
        int d = dis(a.u, b.u);
        if(d + b.r <= a.r) {
            return a;
        }
        int r = (a.r + b.r + dis(a.u, b.u)) / 2, k = r - a.r;
        return C(walk(a.u, b.u, k), r);
    }
    friend int diameter(C a, C b) {
        if(a.r < b.r) swap(a, b);
        int d = dis(a.u, b.u);
        if(d + b.r <= a.r) {
            return a.r;
        }
        return (a.r + b.r + dis(a.u, b.u)) / 2;
    }
}c[N];

struct Divide_Tree {
    struct Info {int p, d, f; };
    vector<Info> opt[N << 1];
    int siz[N], msiz[N], used[N], tot = 0;
    i64 cnt[N << 1], sum[N << 1];
    void find(int u, int fa, int aS, int &rt) {
        siz[u] = 1;
        msiz[u] = 0;
        for(int &v : g[u]) {
            if(v == fa || used[v]) continue;
            find(v, u, aS, rt);
            siz[u] += siz[v];
            msiz[u] = max(msiz[u], siz[v]);
        }
        msiz[u] = max(msiz[u], aS - siz[u]);
        if(rt == -1 || msiz[rt] > msiz[u]) {
            rt = u;
        }
        return;
    }
    
    void inser(int u, int fa, int dep, int f, int rt) {
        opt[u].push_back(Info{rt, dep, f});
        for(int &v : g[u]) {
            if(v == fa || used[v]) continue;
            inser(v, u, dep + 1, f, rt);
        }
        return;
    }

    void dfs(int u, int aS) {
        int c = -1;
        find(u, 0, aS, c);
        inser(c, 0, 0, 1, ++tot);
        used[c] = 1;
        for(int &v : g[c]) {
            if(used[v]) continue;
            inser(v, 0, 1, -1, ++tot);
        }
        for(int &v : g[c]) {
            if(used[v]) continue;
            dfs(v, siz[v]);
        }
        return;
    }
    void modify(int x, int v) {
        for(Info &t : opt[x]) {
            cnt[t.p] += v;
            sum[t.p] += v * t.d;
        }
        return;
    }

    i64 query(int x) {
        i64 res = 0;
        for(Info &t : opt[x]) {
            res += 1ll * t.d * t.f * cnt[t.p];
            res += 1ll * t.f * sum[t.p];
        }
        return res;
    }

    void init() {dfs(1, n * 2 - 1); }

}T;

void divide(int L, int R) {
    if(L == R) return;
    int mid = (L + R) / 2;
    c[mid] = C(mid, 0), c[mid + 1] = C(mid + 1, 0);
    for(int i = mid - 1; i >= L; i--) {
        c[i] = C(i, 0) + c[i + 1];
    }
    for(int i = mid + 2; i <= R; i++) {
        c[i] = C(i, 0) + c[i - 1];
    }
    int p1 = L, p2 = L - 1;
    i64 s1 = 0, s2 = 0;
    for(int i = R; i >= mid + 1; i--) {
        while(p2 + 1 <= mid && diameter(c[p2 + 1], c[i]) > c[i].r) {
            p2++;
            T.modify(c[p2].u, 1);
            s2 += c[p2].r;
        }
        while(p1 <= mid && diameter(c[p1], c[i]) == c[p1].r) {
            s2 -= c[p1].r;
            s1 += c[p1].r;
            T.modify(c[p1].u, -1);
            p1++;
        }
        ans += 1ll * c[i].r * (mid - p2);
        ans += s1;
        ans += (s2 + 1ll * (p2 - p1 + 1) * c[i].r + T.query(c[i].u)) / 2;
    }
    while(p1 <= p2) T.modify(c[p1++].u, -1);
    divide(L, mid), divide(mid + 1, R);
    return ;
}

int main() {
    for(int i = 0; i < K; i++) L2[1 << i] = i;
    cin >> n;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adde(u, n + i), adde(n + i, u);
        adde(v, n + i), adde(n + i, v);
    }
    dep[0] = -1;
    dfs(1, 0);
    T.init();
    divide(1, n);
    printf("%lld\n", ans);
    return 0;
}