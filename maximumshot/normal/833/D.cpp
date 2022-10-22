#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int Sum(int a, int b) {
    return (a + b) % mod;
}

inline int Raz(int a, int b) {
    return ((a - b) % mod + mod) % mod;
}

inline int Mul(int a, int b) {
    return (1ll * a * b) % mod;
}

int binpow(int x, int p) {
    if(p == 0) {
        return 1;
    }else {
        int q = binpow(x, p / 2);
        q = Mul(q, q);
        if(p % 2) q = Mul(q, x);
        return q;
    }
}

int Del(int a, int b) {
    return Mul(a, binpow(b, mod - 2));
}

int const N = 1e5 + 5;

tuple< int, int, int > arr[N];
int szarr;

vec< pii > tree[16 * N];
vec< int > preff[16 * N];

void merge(int v) {
    tree[v].clear();
    int ls = (int)tree[v * 2 + 1].size();
    int rs = (int)tree[v * 2 + 2].size();
    int i = 0;
    int j = 0;
    while(i < ls && j < rs) {
        if(tree[v * 2 + 1][i] > tree[v * 2 + 2][j]) {
            tree[v].push_back(tree[v * 2 + 1][i++]);
        }else {
            tree[v].push_back(tree[v * 2 + 2][j++]);
        }
    }
    while(i < ls) tree[v].push_back(tree[v * 2 + 1][i++]);
    while(j < rs) tree[v].push_back(tree[v * 2 + 2][j++]);
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        tree[v].clear();
        tree[v].push_back(make_pair(get<1>(arr[tl]), get<2>(arr[tl])));
    }else {
        int tm = (tl + tr) / 2;
        build(v * 2 + 1, tl, tm);
        build(v * 2 + 2, tm + 1, tr);
        merge(v);
    }
    preff[v].resize((int)tree[v].size());
    for(int cur = 1, i = 0;i < (int)preff[v].size();i++) {
        cur = Mul(cur, tree[v][i].second);
        preff[v][i] = cur;
    }
}

pii query(int v, int tl, int tr, int l, int r, int x) {
    if(l <= tl && tr <= r) {
        if(tree[v].empty()) return make_pair(1, 0);
        int bl = 0;
        int br = (int)tree[v].size() - 1;
        int bm;
        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if(tree[v][bm].first >= x) {
                bl = bm;
            }else {
                br = bm - 1;
            }
        }
        if(bl < br && tree[v][br].first >= x) {
            return make_pair(preff[v][br], br + 1);
        }else if(tree[v][bl].first >= x) {
            return make_pair(preff[v][bl], bl + 1);
        }else {
            return make_pair(1, 0);
        }
    }else {
        int tm = (tl + tr) / 2;
        pii res = make_pair(1, 0), tmp;
        if(l <= tm) {
            tmp = query(v * 2 + 1, tl, tm, l, r, x);
            res.first = Mul(res.first, tmp.first);
            res.second += tmp.second;
        }
        if(r > tm) {
            tmp = query(v * 2 + 2, tm + 1, tr, l, r, x);
            res.first = Mul(res.first, tmp.first);
            res.second += tmp.second;
        }
        return res;
    }
}

int solve() {

    if(szarr == 0) return 1;

    sort(arr, arr + szarr);

    build(0, 0, szarr - 1);

    int bl, br, bm, bp;

    int res = 1;

    for(int x, y, p, iter = 0;iter < szarr;iter++) {
        tie(x, y, p) = arr[iter];

        if(iter > 0) {
            bl = 0;
            br = iter - 1;
            while(br - bl > 1) {
                bm = (bl + br) / 2;
                if(get<0>(arr[bm]) <= -x) {
                    bl = bm;
                }else {
                    br = bm - 1;
                }
            }
            if(bl < br && get<0>(arr[br]) <= -x) {
                bp = br;
            }else if(get<0>(arr[bl]) <= -x) {
                bp = bl;
            }else {
                bp = -1;
            }
        }else {
            bp = -1;
        }

        if(bp != -1) {
            pii tmp = query(0, 0, szarr - 1, 0, bp, -y);
            res = Mul(res, Mul(tmp.first, binpow(p, tmp.second)));
        }
    }

    return res;
}

int n;
vec< pair< int, pii > > g[N];
// {to, {p, c}}

bool used[N];
int dp[N];
int tot = 1;

void go(int v, int par = -1) {
    dp[v] = 1;
    for(auto iter : g[v]) {
        int to = iter.first;
        if(to == par || used[to]) continue;
        go(to, v);
        dp[v] += dp[to];
    }
}

void find(int v, int par, int & centroid, int Size) {
    int mx = Size - dp[v];
    for(auto iter : g[v]) {
        int to = iter.first;
        if(to == par || used[to]) continue;
        find(to, v, centroid, Size);
        mx = max(mx, dp[to]);
    }
    if(centroid == -1 && 2 * mx <= Size) {
        centroid = v;
    }
}

void asgn(int v, int par, int p, int d, int c) {
    arr[szarr++] = make_tuple(d - 3 * c, 2 * d - 3 * c, p);
    for(auto iter : g[v]) {
        int to;
        to = iter.first;
        if(to == par || used[to]) continue;
        int pto, cto;
        tie(pto, cto) = iter.second;
        asgn(to, v, Mul(p, pto), d + 1, c + cto);
    }
}

void work(int v) {
    go(v);
    int Size = dp[v];
    int centroid = -1;
    find(v, -1, centroid, Size);

    used[centroid] = 1;

    szarr = 0;
    asgn(centroid, -1, 1, 0, 0);

    tot = Mul(tot, solve());

    szarr = 0;

    for(auto iter : g[centroid]) {
        int to = iter.first;
        if(used[to]) continue;
        int pto, cto;
        tie(pto, cto) = iter.second;
        szarr = 0;
        asgn(to, centroid, pto, 1, cto);
        tot = Del(tot, solve());
    }

    for(auto iter : g[centroid]) {
        int to = iter.first;
        if(used[to]) continue;
        work(to);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int p, c, u, v, i = 1;i < n;i++) {
        scanf("%d %d %d %d", &u, &v, &p, &c);
        g[u].push_back(make_pair(v, make_pair(p, c)));
        g[v].push_back(make_pair(u, make_pair(p, c)));
    }

    work(1);

    printf("%d\n", tot);

    return 0;
}