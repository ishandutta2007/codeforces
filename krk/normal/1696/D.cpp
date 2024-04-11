#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxk = 20;

int T;
int n;
int a[Maxn];
ii mn[Maxn][Maxk];
ii mx[Maxn][Maxk];

ii getMin(int l, int r)
{
    ii res = ii(Maxn, -1);
    for (int i = Maxk - 1; i >= 0; i--)
        if (l + (1 << i) <= r + 1) {
            res = min(res, mn[l][i]);
            l += 1 << i;
        }
    return res;
}

ii getMax(int l, int r)
{
    ii res = ii(-Maxn, -1);
    for (int i = Maxk - 1; i >= 0; i--)
        if (l + (1 << i) <= r + 1) {
            res = max(res, mx[l][i]);
            l += 1 << i;
        }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            mn[i][0] = ii(a[i], i);
            mx[i][0] = ii(a[i], i);
        }
        for (int j = 1; j < Maxk; j++)
            for (int i = 1; i + (1 << j) <= n + 1; i++) {
                mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
            }
        int res = 0;
        int ind = getMin(1, n).second;
        bool flagmx = true;
        int from = ind - 1;
        while (from >= 1) {
            res++;
            if (flagmx) from = getMax(1, from).second - 1;
            else from = getMin(1, from).second - 1;
            flagmx = !flagmx;
        }
        flagmx = true;
        from = ind + 1;
        while (from <= n) {
            res++;
            if (flagmx) from = getMax(from, n).second + 1;
            else from = getMin(from, n).second + 1;
            flagmx = !flagmx;
        }
        printf("%d\n", res);
    }
    return 0;
}