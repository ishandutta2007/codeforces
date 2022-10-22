#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int Maxm = 5005;
const int Maxb = 12;
const ll Inf = 1000000000000000000ll;

int tims[1 << Maxb];
int n, m;
int L[Maxn];
int S[Maxn];
int C[Maxm];
ll dp[Maxn][1 << Maxb];
ll BIT[Maxn];
ll simpl[Maxn][1 << Maxb];

void Insert(int x, ll val)
{
    for (int i = x; i < Maxn; i += i & -i)
        BIT[i] = max(BIT[i], val);
}

ll Get(int x)
{
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res = max(res, BIT[i]);
    return res;
}

int main()
{
    for (int i = 0; i < 1 << Maxb; i++)
        for (int j = 0; j < Maxb; j++)
            if (i & 1 << j) tims[i]++;
            else break;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &L[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &S[i]);
    for (int i = 1; i <= n + m; i++) {
        scanf("%d", &C[i]);
        C[i] += C[i - 1];
    }
    fill((ll*)dp, (ll*)dp + Maxn * (1 << Maxb), -Inf);
    fill((ll*)simpl, (ll*)simpl + Maxn * (1 << Maxb), -Inf);
    for (int i = n; i > 0; i--) {
        dp[i][0] = Get(L[i] - Maxb);
        for (int j = 0; j < Maxb && L[i] - j >= 0; j++)
            for (int z = 0; z < 1 << Maxb; z++)
                dp[i][z >> j] = max(dp[i][z >> j], simpl[L[i] - j][z]);
        for (int j = (1 << Maxb) - 1; j >= 0; j--) if (dp[i][j] > -Inf) {
            int t = tims[j];
            ll add = C[L[i] + t] - C[L[i] - 1] - S[i];
            int nj = (j ^ ((1 << t + 1) - 1));
            dp[i][nj] = max(dp[i][nj], dp[i][j] + add);
        }
        ll best = 0;
        for (int j = 0; j < 1 << Maxb; j++) {
            simpl[L[i]][j] = max(simpl[L[i]][j], dp[i][j]);
            best = max(best, dp[i][j]);
        }
        Insert(L[i], best);
    }
    ll res = 0;
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j < 1 << Maxb; j++)
            res = max(res, simpl[i][j]);
    cout << res << endl;
    return 0;
}