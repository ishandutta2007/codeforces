#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const int Inf = 2000000000;

int T;
int n, k;
int a[Maxn];
int hast[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        fill(hast + 1, hast + n + 1, Inf);
        for (int i = 1; i <= k; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= k; i++) {
            int t; scanf("%d", &t);
            hast[a[i]] = t;
        }
        int cur = Inf;
        for (int i = 1; i <= n; i++) {
            cur = min(cur + 1, hast[i]);
            res[i] = cur;
        }
        cur = Inf;
        for (int i = n; i >= 1; i--) {
            cur = min(cur + 1, hast[i]);
            res[i] = min(res[i], cur);
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}