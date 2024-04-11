#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 1000000;
const int Maxd = 6;

int k;
int F[Maxd];
ll dp[Maxd + 1][Maxn];
int q;
int n;
ll best[Maxn / 10];
ll tenbest[Maxn / 10];
ll res = -Inf;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = res * a;
        p >>= 1; a = a * a;
    }
    return res;
}

int main()
{
    scanf("%d", &k);
    for (int i = 0; i < Maxd; i++)
        scanf("%d", &F[i]);
    fill(dp[Maxd], dp[Maxd] + Maxn, -Inf);
    dp[Maxd][0] = 0;
    for (int i = Maxd - 1; i >= 2; i--) {
        int lim = toPower(10, Maxd - i);
        for (int j = 0; j < lim; j++) {
            dp[i][j] = -Inf;
            int to = min(j / 3, k * 3);
            for (int l = 0; l <= to; l++) {
                int nj = j - 3 * l;
                if (l <= 3 * (k - 1) || nj % 10 == 0)
                    dp[i][j] = max(dp[i][j], dp[i + 1][nj / 10] + ll(F[i]) * l);
            }
        }
    }
    scanf("%d", &q);
    scanf("%d", &n);
    fill(best, best + Maxn / 10, -Inf);
    int to = min(n / 3, k * 3);
    for (int l = 0; l <= to; l++) {
        int nj = n - 3 * l;
        if (l <= 3 * (k - 1) || nj % 10 == 0)
            best[nj / 10] = max(best[nj / 10], ll(F[0]) * l);
    }
    int lim = Maxn / 10;
    for (int i = 0; i < lim; i++) {
        tenbest[i] = best[i];
        for (int j = 1; j < 10 && i + j < lim; j++)
            tenbest[i] = max(tenbest[i], best[i + j]);
    }
    for (int i = 0; i < 10000; i++) {
        int cur = i * 10;
        int to = min((lim - 1 - cur) / 3, k * 3);
        for (int l = 0; l <= to; l++) {
            int got = cur + 3 * l;
            if (l <= 3 * (k - 1))
                res = max(res, dp[2][i] + tenbest[got] + ll(F[1]) * l);
            else res = max(res, dp[2][i] + best[got] + ll(F[1]) * l);
        } 
    }
    cout << res << endl;
    return 0;
}