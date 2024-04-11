#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;
const int Inf = 1000000000;

int n, h, m;
int L[Maxn], R[Maxn], X[Maxn], C[Maxn];
int seq[Maxn];
int gdp[Maxn][Maxn], dp[Maxn][Maxn];
int res;

bool Less(const int &a, const int &b)
{
    return X[a] < X[b];
}

void Add(int h)
{
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++)
            dp[l][r] = gdp[l][r];
        dp[l][l] = max(dp[l][l], h * h);
        for (int r = l; r < n; r++) {
            if (r + 1 < n)
                dp[l][r + 1] = max(dp[l][r + 1], dp[l][r] + h * h);
            for (int r2 = r + 1; r2 < n; r2++)
                dp[l][r2] = max(dp[l][r2], dp[l][r] + gdp[r + 1][r2]);
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &h, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &L[i], &R[i], &X[i], &C[i]);
        L[i]--; R[i]--;
        seq[i] = i;
        res -= C[i];
    }
    sort(seq, seq + m, Less);
    fill((int*)gdp, (int*)gdp + Maxn * Maxn, -Inf);
    for (int i = 0; i < m; i++) {
        int ind = seq[i];
        Add(X[ind]);
        for (int l = 0; l <= L[ind]; l++)
            for (int r = R[ind]; r < n; r++)
                gdp[l][r] = max(gdp[l][r], dp[l][r] + C[ind]);
    }
    Add(h);
    printf("%d\n", res + dp[0][n - 1]);
    return 0;
}