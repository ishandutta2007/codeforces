#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1000000007;
const int Maxn = 505;
const int Maxm = 1000005;

int n;
int A[Maxn], B[Maxn], K[Maxn];
int my[Maxn][Maxn];

ll Get(int n, int m)
{
    vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
    for (int i=1; i<=n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv (m+1, INF);
        vector<char> used (m+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0],  delta = INF,  j1;
            for (int j=1; j<=m; ++j)
                if (!used[j]) {
                    int cur = my[i0][j]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j=0; j<=m; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    ll res = 0;
    for (int i = 1; i <= m; i++)
        res += my[p[i]][i];
    return -res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &A[i], &B[i], &K[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            my[i][j] = -max(0ll, ll(A[i]) - ll(B[i]) * min(j - 1, K[i]));
    cout << Get(n, n) << endl;
    return 0;
}