#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

const int Maxn = 52;

ld C[Maxn][Maxn];
int n;
vector <int> neigh[Maxn];
ld dp[Maxn][2][Maxn];
ld tmp[Maxn];
int sz[Maxn];

void Solve(int v, int p)
{
    dp[v][0][1] = 1.0l;
    dp[v][1][0] = 1.0l / 2.0l;
    sz[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Solve(u, v);
        fill(tmp, tmp + Maxn, 0.0l);
        // 0 from 0
        for (int vlef = 0; vlef <= sz[v]; vlef++) {
            int vrig = sz[v] - vlef;
            for (int ulef = 0; ulef <= sz[u]; ulef++) {
                int urig = sz[u] - ulef;
                tmp[vlef + ulef] += dp[v][0][vlef] * dp[u][0][ulef] * C[vlef + ulef][vlef] * C[vrig + urig][vrig];
            }
        }
        // 0 from 1
        for (int vlef = 0; vlef <= sz[v]; vlef++) {
            int vrig = sz[v] - vlef;
            for (int ulef = 0; ulef < sz[u]; ulef++) {
                int urig = sz[u] - 1 - ulef;
                for (int c = 0; c <= ulef; c++)
                    tmp[vlef + c] += dp[v][0][vlef] * dp[u][1][ulef] * C[vlef + c][vlef] * C[ulef - c + 1 + urig + vrig][vrig];
            }
        }
        for (int j = 0; j <= sz[v] + sz[u]; j++)
            dp[v][0][j] = tmp[j];
        fill(tmp, tmp + Maxn, 0.0l);
        // 1 from 0
        for (int vlef = 0; vlef < sz[v]; vlef++) {
            int vrig = sz[v] - 1 - vlef;
            for (int ulef = 0; ulef <= sz[u]; ulef++) {
                int urig = sz[u] - ulef;
                tmp[vlef + ulef] += dp[v][1][vlef] * dp[u][0][ulef] * C[vlef + ulef][vlef] * C[vrig + urig][vrig];
            }
        }
        // 1 from 1
        for (int vlef = 0; vlef < sz[v]; vlef++) {
            int vrig = sz[v] - 1 - vlef;
            for (int ulef = 0; ulef < sz[u]; ulef++) {
                int urig = sz[u] - 1 - ulef;
                for (int c = 0; c <= ulef; c++)
                    tmp[vlef + c] += dp[v][1][vlef] * dp[u][1][ulef] * C[vlef + c][vlef] * C[ulef - c + 1 + urig + vrig][vrig];
            }
        }
        for (int j = 0; j <= sz[v] + sz[u]; j++)
            dp[v][1][j] = tmp[j];
        sz[v] += sz[u];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    ld fac = 1;
    for (int i = 1; i <= n - 1; i++)
        fac *= i;
    for (int r = 1; r <= n; r++) {
        fill((ld*)dp, (ld*)dp + Maxn * 2 * Maxn, 0.0l);
        fill(sz, sz + Maxn, 0);
        ld res = 1.0l;
        int cur = 0;
        for (int i = 0; i < neigh[r].size(); i++) {
            int v = neigh[r][i];
            Solve(v, r);
            ld all = 0;
            for (int j = 0; j < sz[v]; j++)
                all += dp[v][1][j];
            res *= all * C[cur + sz[v]][cur];
            cur += sz[v];
        }
        cout << fixed << setprecision(10) << res / fac << endl;
    }
    return 0;
}