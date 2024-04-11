#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxk = 20;

int n, m;
int mx[Maxn][Maxk];

int getMax(int l, int r)
{
    if (l > r) swap(l, r);
    int res = 0;
    for (int i = Maxk - 1; i >= 0; i--)
        if (l + (1 << i) <= r + 1) {
            res = max(res, mx[l][i]);
            l += 1 << i;
        }
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &mx[i][0]);
    for (int j = 1; j < Maxk; j++)
        for (int i = 1; i + (1 << j) <= m + 1; i++)
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
    int q; scanf("%d", &q);
    while (q--) {
        int r1, c1, r2, c2, k; scanf("%d %d %d %d %d", &r1, &c1, &r2, &c2, &k);
        if ((r1 - r2) % k || (c1 - c2) % k) { printf("NO\n"); continue; }
        int mx = getMax(c1, c2);
        if (mx < max(r1, r2)) { printf("YES\n"); continue; }
        int steps = (mx - r1) / k + 1;
        long long wh = r1 + steps * k;
        printf("%s\n", wh <= n? "YES": "NO");
    }
    return 0;
}