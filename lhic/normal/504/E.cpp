#pragma GCC optimize "-Ofast"
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 310000;
const ll MOD1 = 1000000007;
const ll P = 23917;
int was[MAXN];
int h[MAXN];
ll hs[MAXN];
ll hs2[MAXN];
int p[MAXN];
char s[MAXN];
int n;
vector<int> eds[MAXN];
ll pw[MAXN];
ll pwb[MAXN];
int tm;
int cnt;
int q;
vector<pair<int, int> > gg[MAXN];
int pp[MAXN];
pair<int, int> dd[2010000];
int lc[2010000];
int pl[MAXN];
int gr[MAXN];
int sz[MAXN];
struct st {
    int l, r, gr;
};

struct way {
    vector<int> vv;
    int p;
    int k;
};

way cm[MAXN];



ll pw2(ll a, ll b, ll MOD) {
    ll ans = 1;
    while (b) {
        while (!(b & 1))
            b >>= 1, a = (a * a) % MOD;
        --b;
        ans = (ans * a) % MOD;
    }
    return ans;
}

int get(int v) {
    if (pp[v] == v)
        return v;
    return pp[v] = get(pp[v]);
}

void un(int a, int b) {
    a = get(a);
    b = get(b);
    pp[b] = a;
}

ll getHs(int a, int b) {
    if (b == 0)
        return hs[a];
    b = p[b];
    return (hs[a] - (hs[b] * pw[h[a] - h[b]]) + MOD1 * MOD1) % MOD1;
}

ll getHsRev(int a, int b) {
    if (b == 0)
        return hs2[a];
    b = p[b];
    return ((hs2[a] - hs2[b] + MOD1) * pwb[h[b] + 1]) % MOD1;
}

void dfs(int v, int hh, ll hs1, ll hs22) {
    h[v] = hh;
    hs1 = (hs1 * P + s[v]) % MOD1;
    hs22 = (hs22 + s[v] * pw[hh]) % MOD1;
    hs[v] = hs1;
    hs2[v] = hs22;
    was[v] = 1;
    sz[v] = 1;
    for (int i = 0; i < (int)gg[v].size(); ++i) {
        int u = gg[v][i].first;
        if (was[u])
            lc[gg[v][i].second] = get(u);
    }
    for (int i = 0; i < (int)eds[v].size(); ++i) {
        int u = eds[v][i];
        if (was[u])
            continue;
        p[u] = v;
        dfs(u, hh + 1, hs1, hs22);
        un(v, u);
        sz[v] += sz[u];
    }
}

int cc = 0;


void dfs2(int v, int c) {
    gr[v] = c;
    pl[v] = cm[c].vv.size();
    cm[c].vv.push_back(v);
    int mx = 0;
    was[v] = 1;
    for (int i = 0; i < (int)eds[v].size(); ++i)
        if (!was[eds[v][i]])
            mx = max(mx, sz[eds[v][i]]);
    int fl = 0;
    for (int i = 0; i < (int)eds[v].size(); ++i) {
        int u = eds[v][i];
        if (was[u])
            continue;
        if (sz[u] == mx && !fl) {
            fl = 1;
            dfs2(u, c);
        }
        else {
            ++cc;
            cm[cc].p = v;
            dfs2(u, cc);
        }
    }
}


void init() {
    pw[0] = 1;
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        pw[i] = (pw[i - 1] * P) % MOD1;
    ll p1 = pw2(P, MOD1 - 2, MOD1);
    pwb[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        pwb[i] = (pwb[i - 1] * p1) % MOD1;

    for (int i = 0; i < 2 * q; ++i) {
        int a = dd[i].first;
        int b = dd[i].second;
        gg[a].push_back(make_pair(b, i));
        gg[b].push_back(make_pair(a, i));
    }

    for (int i = 0; i < n; ++i)
        pp[i] = i;
    memset(was, 0, sizeof(was));
    p[0] = 0;
    dfs(0, 0, 0, 0);
    memset(was, 0, sizeof(was));
    dfs2(0, 0);
    cm[0].p = -1;
    ++cc;
    for (int i = 0; i < cc; ++i)
        cm[i].k = i;
}

ll getHsGr(st a, int len) {
    if (a.l <= a.r)
        return getHsRev(cm[a.gr].vv[a.l + len - 1], cm[a.gr].vv[a.l]);
    else
        return getHs(cm[a.gr].vv[a.l], cm[a.gr].vv[a.l - len + 1]);
}

st vv1[50];
st vv2[50];
st tmp[50];

int decomp(int a, int b, int lca, st vv[]) {
    int cnt = 0;
    while (gr[a] != gr[lca]) {
        st x;
        x.l = pl[a];
        x.r = 0;
        x.gr = gr[a];
        vv[cnt++] = x;
        a = cm[gr[a]].p;
    }
    st x;
    x.l = pl[a];
    x.r = pl[lca];
    x.gr = gr[a];
    vv[cnt++] = x;
    int cnt2 = 0;
    while (gr[b] != gr[lca]) {
        st x;
        x.r = pl[b];
        x.l = 0;
        x.gr = gr[b];
        tmp[cnt2++] = x;
        b = cm[gr[b]].p;
    }
    if (pl[b] != pl[lca]) {
        st x;
        x.l = pl[lca] + 1;
        x.r = pl[b];
        x.gr = gr[b];
        vv[cnt++] = x;
    }
    for (int i = cnt2 - 1; i >= 0; --i)
        vv[cnt++] = tmp[i];
    return cnt;
}





int main() {
    //int start = clock();
    //int sm = 0;
    //freopen("in2", "r", stdin);
    //freopen("out1", "w", stdout);
    scanf("%d", &n);
    scanf(" %s", s);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        eds[a].push_back(b);
        eds[b].push_back(a);
    }
    scanf("%d", &q);
    for (int it = 0; it < q; ++it) {
        int a1, b1, a2, b2;
        scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
        --a1, --b1, --a2, --b2;
        dd[it * 2] = make_pair(a1, b1);
        dd[it * 2 + 1] = make_pair(a2, b2);
    }
    init();
    for (int it = 0; it < q; ++it) {
        int a1, b1, a2, b2;
        tie(a1, b1) = dd[it * 2];
        tie(a2, b2) = dd[it * 2 + 1];
        int x1 = lc[it * 2];
        int x2 = lc[it * 2 + 1];
    //  sm -= clock();
        int cnt1 = decomp(a1, b1, x1, vv1);
        int cnt2 = decomp(a2, b2, x2, vv2);
    //  sm += clock();
        int ans = 0;
        int n1 = 0, n2 = 0;
        while (n1 < cnt1 && n2 < cnt2) {
            int len = min(abs(vv1[n1].l - vv1[n1].r), abs(vv2[n2].l - vv2[n2].r)) + 1;
            ll hh1;
            ll hh2;
            hh1 = getHsGr(vv1[n1], len);
            hh2 = getHsGr(vv2[n2], len);
            if (hh1 == hh2) {
                ans += len;
                if (vv1[n1].l <= vv1[n1].r) {
                    vv1[n1].l += len;
                    if (vv1[n1].l > vv1[n1].r)
                        ++n1;
                }
                else {
                    vv1[n1].l -= len;
                    if (vv1[n1].l < vv1[n1].r)
                        ++n1;
                }
                if (vv2[n2].l <= vv2[n2].r) {
                    vv2[n2].l += len;
                    if (vv2[n2].l > vv2[n2].r)
                        ++n2;
                }
                else {
                    vv2[n2].l -= len;
                    if (vv2[n2].l < vv2[n2].r)
                        ++n2;
                }
            }
            else {
                int l = 0;
                int r = len;
                while (r - l > 1) {
                    int mm = (l + r) >> 1;
                    if (getHsGr(vv1[n1], mm) == getHsGr(vv2[n2], mm))
                        l = mm;
                    else
                        r = mm;
                }
                ans += l;
                break;
            }
        }
        printf("%d\n", ans);
    }
    //cerr << (ld)(sm) / (clock() - start) << "\n";
    return 0;
}