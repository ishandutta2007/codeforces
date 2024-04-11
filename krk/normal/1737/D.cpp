#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 505;
const int Maxm = 300005;
const ll Inf = 1000000000000000000ll;
const int sInf = 1000000000;

int T;
int n, m;
int A[Maxm], B[Maxm], C[Maxm];
int dist[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = (i != j) * sInf;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &A[i], &B[i], &C[i]);
            dist[A[i]][B[i]] = dist[B[i]][A[i]] = 1;
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        ll res = Inf;
        for (int i = 0; i < m; i++) {
            int cand = min(dist[1][A[i]] + dist[B[i]][n], dist[1][B[i]] + dist[A[i]][n]) + 1;
            res = min(res, ll(cand) * C[i]);
            for (int k = 1; k <= n; k++) {
                int d = min(dist[k][A[i]], dist[k][B[i]]);
                res = min(res, ll(d + dist[1][k] + 2 + dist[k][n]) * C[i]);
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}