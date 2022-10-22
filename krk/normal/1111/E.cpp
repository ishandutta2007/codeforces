#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 20;
const int Maxk = 305;
const int mod = 1000000007;

int fac[Maxk], inv[Maxk];
int C[Maxk][Maxk];
int n, q;
vector <int> neigh[Maxn];
vector <int> tneigh[Maxn];
int P[Maxn][Maxm], L[Maxn];
int cur, lef[Maxn], rig[Maxn];
bool mark[Maxn];
int seq[Maxn];
int k, m, r;
int res[Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

void Traverse(int v)
{
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v][0] == u) continue;
        P[u][0] = v; L[u] = L[v] + 1;
        Traverse(u);
    }
    rig[v] = cur;
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

void Compute(int v, int p, int ab = 0)
{
    if (mark[v]) {
        for (int i = 1; i <= m; i++)
            if (i <= ab) res[i] = 0;
            else res[i] = ll(res[i]) * (i - ab) % mod;
        ab++;
    }
    for (int i = 0; i < tneigh[v].size(); i++) {
        int u = tneigh[v][i];
        if (u == p) continue;
        Compute(u, v, ab);
    }
}

int Solve()
{
    vector <ii> imp;
    for (int i = 0; i < k; i++) {
        mark[seq[i]] = true;
        imp.push_back(ii(lef[seq[i]], seq[i]));
    }
    if (!mark[r]) imp.push_back(ii(lef[r], r));
    sort(imp.begin(), imp.end());
    int lim = imp.size();
    for (int i = 0; i + 1 < lim; i++) {
        int lca = getLCA(imp[i].second, imp[i + 1].second);
        imp.push_back(ii(lef[lca], lca));
    }
    sort(imp.begin(), imp.end());
    imp.erase(unique(imp.begin(), imp.end()), imp.end());
    for (int i = 0; i < imp.size(); i++)
        tneigh[imp[i].second].clear();
    vector <int> S;
    for (int i = 0; i < imp.size(); i++) {
        while (!S.empty() && rig[S.back()] < imp[i].first)
            S.pop_back();
        if (!S.empty()) {
            tneigh[S.back()].push_back(imp[i].second);
            tneigh[imp[i].second].push_back(S.back());
        }
        S.push_back(imp[i].second);
    }
    fill(res + 1, res + m + 1, 1);
    Compute(r, 0);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j < i; j++)
            res[i] = (res[i] - ll(C[i][j]) * res[j] % mod + mod) % mod;
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + ll(res[i]) * inv[i]) % mod;
    for (int i = 0; i < k; i++)
        mark[seq[i]] = false;
    return ans;
}

int main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxk; i++) {
        fac[i] = ll(fac[i - 1]) * i % mod;
        inv[i] = Inv(fac[i]);
    }
    for (int i = 0; i < Maxk; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1);
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i <= n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];
    while (q--) {
        scanf("%d %d %d", &k, &m, &r);
        for (int i = 0; i < k; i++)
            scanf("%d", &seq[i]);
        printf("%d\n", Solve());
    }
    return 0;
}