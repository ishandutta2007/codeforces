#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 840;
const int Maxn = 10;
const ll Inf = 4000000000000000000ll;

ll W;
ll a[Maxn];
ll has[Maxn][Maxm];
ll res;

int main()
{
    cin >> W;
    for (int i = 1; i + 1 < Maxn; i++)
        scanf("%I64d", &a[i]);
    fill((ll*)has, (ll*)has + Maxn * Maxm, -Inf);
    has[1][0] = 0;
    for (int i = 1; i + 1 < Maxn; i++)
        for (int j = 0; j < Maxm; j++) if (has[i][j] > -Inf)
            for (int k = 0; k < Maxm && k <= a[i]; k++) {
                ll nj = j + ll(k) * i;
                has[i + 1][nj % Maxm] = max(has[i + 1][nj % Maxm],
                                            has[i][j] + (a[i] - k) / (Maxm / i) + nj / Maxm);
            }
    for (int j = 0; j < Maxm && j <= W; j++) if (has[Maxn - 1][j] > -Inf)
        res = max(res, min(ll(W - j) / Maxm, has[Maxn - 1][j]) * ll(Maxm) + j);
    cout << res << endl;
    return 0;
}