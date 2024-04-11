#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;
const int Maxm = 20;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, q;
ll vals[Maxn];
int a[Maxn];
vector <int> my[Maxn];
vector <int> neigh[Maxn];
int lefcnt, lef[Maxn], rig[Maxn];
int L[Maxn], P[Maxn][Maxm];
ll BIT[Maxn];
int qa[Maxn], qb[Maxn], ql[Maxn], qr[Maxn], qsav[Maxn];
int qlca[Maxn];
ll xr[Maxn];
int cur;
vector <int> bef[2][Maxn], aft[2][Maxn];
int res[Maxn];

void Insert(int x, ll val)
{
    for (int i = x; i <= n; i += i & -i)
        BIT[i] ^= val;
}

ll Get(int x)
{
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res ^= BIT[i];
    return res;
}

void Traverse(int v)
{
    lef[v] = ++lefcnt;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == P[v][0]) continue;
        L[u] = L[v] + 1;
        P[u][0] = v;
        Traverse(u);
    }
    rig[v] = lefcnt;
}

int getLCA(int a, int b)
{
    if (L[a] < L[b]) swap(a, b);
    for (int i = Maxm - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b])
            a = P[a][i];
    if (a == b) return a;
    for (int i = Maxm - 1; i >= 0; i--)
        if (P[a][i] != P[b][i])
            a = P[a][i], b = P[b][i];
    return P[a][0];
}

ll getXor(int ind)
{
    ll res = (Get(lef[qa[ind]]) ^ Get(lef[qb[ind]]) ^ Get(lef[qlca[ind]]));
    if (qlca[ind] != 1) res ^= Get(lef[P[qlca[ind]][0]]);
    return res;
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        vals[i] = uniform_int_distribution<ll>(1ll, (1ll << 60ll) - 1ll)(rng);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        my[a[i]].push_back(i);
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1);
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i <= n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &qa[i], &qb[i], &ql[i], &qr[i]);
        qsav[i] = qr[i];
        qlca[i] = getLCA(qa[i], qb[i]);
        bef[cur][ql[i]].push_back(i);
        int m = ql[i] + qr[i] >> 1;
        aft[cur][m].push_back(i);
    }
    for (int t = 0; t < 20; t++) {
        fill(BIT, BIT + n + 1, 0ll);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < bef[cur][i].size(); j++) {
                int ind = bef[cur][i][j];
                xr[ind] = getXor(ind);
            }
            bef[cur][i].clear();
            for (int j = 0; j < my[i].size(); j++) {
                int v = my[i][j];
                Insert(lef[v], vals[i]);
                Insert(rig[v] + 1, vals[i]);
            }
            for (int j = 0; j < aft[cur][i].size(); j++) {
                int ind = aft[cur][i][j];
                ll got = getXor(ind);
                if (got != xr[ind]) qr[ind] = i - 1;
                else ql[ind] = i + 1;
                if (ql[ind] <= qr[ind]) {
                    int m = ql[ind] + qr[ind] >> 1;
                    bef[!cur][ql[ind]].push_back(ind);
                    aft[!cur][m].push_back(ind);
                }
            }
            aft[cur][i].clear();
        }
        cur = !cur;
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", ql[i] <= qsav[i]? ql[i]: -1);
    return 0;
}