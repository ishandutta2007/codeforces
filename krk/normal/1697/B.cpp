#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, q;
int p[Maxn];
ll sum[Maxn];

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + p[i];
    while (q--) {
        int x, y; scanf("%d %d", &y, &x);
        printf("%I64d\n", sum[n - y + x] - sum[n - y]);
    }
    return 0;
}