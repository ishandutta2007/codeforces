#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int mod = 1000000007;

int nd = 1;
int m, n;
int add[Maxn][2];
vector <int> seq[Maxn];
ii zer[Maxn];
vector <ii> neigh[Maxn];
bool tk[Maxn];
int cur, dp[2][2][2];
int res[2];

int Get(int a, int b, int ind, int va, int vb)
{
    if (seq[ind][0] == a) return zer[ind] != ii(va, vb);
    else return zer[ind] != ii(vb, va);
}

void addNw(int nw[])
{
    int nres0 = (ll(res[0]) * nw[0] + ll(res[1]) * nw[1]) % mod;
    int nres1 = (ll(res[0]) * nw[1] + ll(res[1]) * nw[0]) % mod;
    res[0] = nres0;
    res[1] = nres1;
}

void addLine(int v)
{
    fill((int*)dp, (int*)dp + 2 * 2 * 2, 0);
    dp[cur][0][add[v][0]] = 1;
    dp[cur][1][add[v][1]] = 1;
    int par = -1;
    tk[v] = true;
    while (true) {
        int pnt = 0;
        while (pnt < neigh[v].size() && neigh[v][pnt].second == par) pnt++;
        if (pnt >= neigh[v].size()) break;
        int u = neigh[v][pnt].first;
        par = neigh[v][pnt].second;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) if (dp[cur][i][j]) {
                int ways = dp[cur][i][j]; dp[cur][i][j] = 0;
                for (int z = 0; z < 2; z++) {
                    int nj = (j + Get(v, u, par, i, z) + add[u][z]) % 2;
                    dp[!cur][z][nj] = (dp[!cur][z][nj] + ways) % mod;
                }
            }
        v = u; tk[v] = true;
        cur = !cur;
    }
    int nw[2] = {};
    nw[0] = (dp[cur][0][0] + dp[cur][1][0]) % mod;
    nw[1] = (dp[cur][0][1] + dp[cur][1][1]) % mod;
    addNw(nw);
}

void addCycle(int v)
{
    int mem = v;
    int nw[2] = {};
    for (int t = 0; t < 2; t++) {
        fill((int*)dp, (int*)dp + 2 * 2 * 2, 0);
        v = mem;
        dp[cur][t][add[v][t]] = 1;
        int par = -1;
        tk[v] = true;
        while (true) {
            int pnt = 0;
            while (pnt < neigh[v].size() && neigh[v][pnt].second == par) pnt++;
            if (pnt >= neigh[v].size()) break;
            int u = neigh[v][pnt].first;
            par = neigh[v][pnt].second;
            if (u == mem) break;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++) if (dp[cur][i][j]) {
                    int ways = dp[cur][i][j]; dp[cur][i][j] = 0;
                    for (int z = 0; z < 2; z++) {
                        int nj = (j + Get(v, u, par, i, z) + add[u][z]) % 2;
                        dp[!cur][z][nj] = (dp[!cur][z][nj] + ways) % mod;
                    }
                }
            v = u; tk[v] = true;
            cur = !cur;
        }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                int nj = (j + Get(v, mem, par, i, t)) % 2;
                nw[nj] = (nw[nj] + dp[cur][i][j]) % mod;
            }
    }
    addNw(nw);
}

int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        int k; scanf("%d", &k);
        seq[i].resize(k);
        for (int j = 0; j < k; j++)
            scanf("%d", &seq[i][j]);
        if (k == 1) {
            int a = seq[i][0];
            bool neg = a < 0;
            seq[i][0] = a = abs(a);
            add[a][!neg] = (add[a][!neg] + 1) % 2;
        } else {
            int a = seq[i][0], b = seq[i][1];
            bool nega = a < 0;
            seq[i][0] = a = abs(a);
            bool negb = b < 0;
            seq[i][1] = b = abs(b);
            if (a == b)
                if (nega != negb) nd = 1 - nd;
                else add[a][!nega] = (add[a][!nega] + 1) % 2;
            else {
                neigh[a].push_back(ii(b, i));
                neigh[b].push_back(ii(a, i));
                zer[i] = ii(nega, negb);
            }
        }
    }
    res[0] = 1;
    for (int i = 1; i <= n; i++) if (!tk[i] && neigh[i].size() < 2)
        addLine(i);
    for (int i = 1; i <= n; i++) if (!tk[i])
        addCycle(i);
    cout << res[nd] << endl;
    return 0;
}