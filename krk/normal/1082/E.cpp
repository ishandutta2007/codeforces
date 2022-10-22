#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;

int n, c;
int a[Maxn];
int R[Maxn];
int best[Maxn], cnt[Maxn];
int res;

int main()
{
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = n; i > 0; i--)
        R[i] = R[i + 1] + (a[i] == c);
    int wasc = 0;
    for (int i = 1; i <= n; i++) {
        best[a[i]] = max(best[a[i]], wasc - cnt[a[i]]);
        cnt[a[i]]++;
        res = max(res, best[a[i]] + cnt[a[i]] + R[i + 1]);
        wasc += a[i] == c;
    }
    res = max(res, wasc);
    printf("%d\n", res);
    return 0;
}