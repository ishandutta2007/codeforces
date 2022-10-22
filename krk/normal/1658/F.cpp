#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, m;
char str[Maxn];
ll a[Maxn];
ll sum[Maxn];

void Solve()
{
    for (int i = m; i <= n; i++)
        if (sum[i] - sum[i - m] == 0) {
            printf("1\n");
            printf("%d %d\n", i - m + 1, i);
            return;
        }
    for (int i = 1; i < m; i++)
        if (sum[i] + sum[n] - sum[n - (m - i)] == 0) {
            printf("2\n");
            printf("1 %d\n", i);
            printf("%d %d\n", n - (m - i) + 1, n);
            return;
        }
    printf("-1\n");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        scanf("%s", str + 1);
        int ones = 0;
        for (int i = 1; i <= n; i++)
            if (str[i] == '1') ones++;
        for (int i = 1; i <= n; i++) {
            a[i] = ll(str[i] - '0') * ll(n) - ll(ones);
            sum[i] = sum[i - 1] + a[i];
        }
        Solve();
    }
    return 0;
}