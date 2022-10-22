#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxd = 5;

int T;
int n, k, z;
int a[Maxn];
int best[Maxd];
int res;

void addBest(int x)
{
    if (best[Maxd - 1] >= x) return;
    best[Maxd - 1] = x;
    for (int i = Maxd - 1; i > 0 && best[i] > best[i - 1]; i--)
        swap(best[i], best[i - 1]);
}

int Get(int x)
{
    x = min(x, z);
    int res = 0;
    for (int i = 0; i < x; i++)
        res += best[0];
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &k, &z);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        fill(best, best + Maxd, 0);
        int cur = a[1];
        res = 0;
        for (int i = 2; i <= n && k >= 0; i++) {
            addBest(a[i - 1] + a[i]);
            res = max(res, cur + Get(k / 2));
            if (k == 0) break;
            cur += a[i]; k--;
            res = max(res, cur + Get(k / 2));
        }
        printf("%d\n", res);
    }
    return 0;
}