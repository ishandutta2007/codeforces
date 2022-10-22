#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n;
int B[Maxn][2];
ll sum[Maxn];
ll best[Maxn][2], spec[Maxn][2];

int main()
{
    scanf("%d", &n);
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < n; i++)
            scanf("%d", &B[i][j]);
    for (int i = n - 1; i >= 0; i--)
        sum[i] = sum[i + 1] + B[i][0] + B[i][1];
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < 2; j++) {
            spec[i][j] = spec[i + 1][j] + sum[i + 1] + ll(2 * (n - i) - 1) * B[i][1 - j];
            best[i][j] = max(spec[i][j], B[i][1 - j] + best[i + 1][1 - j] + 2 * sum[i + 1]);
        }
    ll res = best[0][0];
    cout << res << endl;
    return 0;
}