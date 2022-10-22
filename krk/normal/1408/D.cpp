#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int n, m;
int a[Maxn], b[Maxn];
int c[Maxn], d[Maxn];
int mx[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i], &b[i]);
    for (int j = 0; j < m; j++) {
        scanf("%d %d", &c[j], &d[j]);
        for (int i = 0; i < n; i++)
            if (a[i] <= c[j] && b[i] <= d[j])
                mx[c[j] - a[i]] = max(mx[c[j] - a[i]], d[j] - b[i] + 1);
    }
    for (int i = Maxn - 2; i >= 0; i--)
        mx[i] = max(mx[i], mx[i + 1]);
    int res = Maxn;
    for (int i = 0; i < Maxn; i++)
        res = min(res, i + mx[i]);
    printf("%d\n", res);
    return 0;
}