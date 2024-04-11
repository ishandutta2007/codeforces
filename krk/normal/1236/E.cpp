#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int nil = 200015;

int n, m;
int a[Maxn];
int res[Maxn];
int L[Maxn], R[Maxn];
ll tot;

int main()
{
    scanf("%d %d", &n, &m);
    if (n == 1) { printf("0\n"); return 0; }
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    for (int i = m; i > 0; i--)
        res[a[i] - i + nil] = res[a[i] - i + nil - 1] + 1;
    for (int i = 1; i <= n; i++)
        R[i] = min(n, i + m + 1 - res[i + nil]);
    fill(res, res + Maxn, 0);
    for (int i = m; i > 0; i--)
        res[a[i] + i] = res[a[i] + i + 1] + 1;
    for (int i = 1; i <= n; i++) {
        L[i] = max(1, i - m - 1 + res[i]);
        tot += R[i] - L[i] + 1;
    }
    printf("%I64d\n", tot);
    return 0;
}