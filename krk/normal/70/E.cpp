#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 205;

int n, k;
int dist[Maxn];
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int inlef[Maxn];
int lca[Maxn][Maxn];
int L[Maxn], P[Maxn];
int dp[Maxn][Maxn][Maxn];
int res[Maxn];

void Precompute(int v)
{
    lef[v] = ++cur; inlef[cur] = v;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v] == u) continue;
        P[u] = v; L[u] = L[v] + 1;
        Precompute(u);
    }
    rig[v] = cur;
}

int getLCA(int a, int b)
{
    if (lca[a][b]) return lca[a][b];
    int v1 = a, v2 = b;
    while (v1 != v2)
        if (L[v1] >= L[v2]) v1 = P[v1];
        else v2 = P[v2];
    return lca[a][b] = v1;
}

int getDist(int a, int b)
{
    if (a == b) return 0;
    if (a == 0 || b == 0) return Inf;
    return L[a] + L[b] - 2 * L[getLCA(a, b)];
}

int Solve(int a, int b, int c)
{
    if (dp[a][b][c] != -1) return dp[a][b][c];
    if (c == 0) {
        int res = Inf;
        vector <int> seq;
        seq.push_back(0);
        for (int i = lef[b]; i <= rig[b]; i++)
            seq.push_back(inlef[i]);
        for (int z = 0; z < seq.size(); z++) {
            int cand = 0;
            int best = min(getDist(a, b), getDist(seq[z], b));
            if (best == Inf) continue;
            cand += dist[best];
            for (int i = 0; i < neigh[b].size(); i++) {
                int u = neigh[b][i];
                if (P[b] == u) continue;
                cand += Solve(a, u, seq[z]);
            }
            res = min(res, cand);
        }
        return dp[a][b][c] = res;
    }
    if (lef[c] < lef[b] || rig[b] < lef[c])
        return dp[a][b][c] = Solve((getDist(a, b) <= getDist(c, b)? a: c), b, 0);
    int best = min(getDist(a, b), getDist(c, b));
    int res = best == Inf? Inf: dist[best];
    for (int i = 0; i < neigh[b].size(); i++) {
        int u = neigh[b][i];
        if (P[b] == u) continue;
        res += Solve(a, u, c);
    }
    return dp[a][b][c] = res;
}

void getRes(int a, int b, int c)
{
    if (c == 0) {
        vector <int> seq;
        seq.push_back(0);
        for (int i = lef[b]; i <= rig[b]; i++)
            seq.push_back(inlef[i]);
        for (int z = 0; z < seq.size(); z++) {
            int cand = 0;
            int best = min(getDist(a, b), getDist(seq[z], b));
            if (best == Inf) continue;
            cand += dist[best];
            for (int i = 0; i < neigh[b].size(); i++) {
                int u = neigh[b][i];
                if (P[b] == u) continue;
                cand += Solve(a, u, seq[z]);
            }
            if (cand == dp[a][b][c]) {
                res[b] = getDist(a, b) <= getDist(seq[z], b)? a: seq[z];
                for (int i = 0; i < neigh[b].size(); i++) {
                    int u = neigh[b][i];
                    if (P[b] == u) continue;
                    getRes(a, u, seq[z]);
                }
                return;
            }
        }
    }
    if (lef[c] < lef[b] || rig[b] < lef[c]) {
        getRes((getDist(a, b) <= getDist(c, b)? a: c), b, 0);
        return;
    }
    res[b] = getDist(a, b) <= getDist(c, b)? a: c;
    for (int i = 0; i < neigh[b].size(); i++) {
        int u = neigh[b][i];
        if (P[b] == u) continue;
        getRes(a, u, c);
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n - 1; i++)
        scanf("%d", &dist[i]);
    dist[0] = k;
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Precompute(1);
    fill((int*)dp, (int*)dp + Maxn * Maxn * Maxn, -1);
    cout << Solve(0, 1, 0) << endl;
    getRes(0, 1, 0);
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}