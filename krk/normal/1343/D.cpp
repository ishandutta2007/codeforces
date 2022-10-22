#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;

int T;
int n, k;
int a[Maxn];
int delt[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        fill(delt, delt + 2 * k + 1, 0);
        for (int i = 0; i < n / 2; i++) {
            int u = a[i], v = a[n - 1 - i];
            if (u > v) swap(u, v);
            delt[2] += 2;
            delt[u + 1] -= 1;
            delt[u + v] -= 1;
            delt[u + v + 1] += 1;
            delt[v + k + 1] += 1;
        }
        int res = Maxn;
        int cur = 0;
        for (int i = 2; i <= 2 * k; i++) {
            cur += delt[i];
            res = min(res, cur);
        }
        printf("%d\n", res);
    }
    return 0;
}