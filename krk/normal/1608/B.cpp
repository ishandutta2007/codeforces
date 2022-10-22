#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, a, b;
int cur[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &a, &b);
        if (a + b > n - 2 || abs(a - b) > 1) { printf("-1\n"); continue; }
        bool mx = a >= b;
        int lef = 1, rig = n;
        cur[0] = cur[n - 1] = 0;
        for (int i = 1; i + 1 < n; i++) {
            if (mx)
                if (a > 0) { cur[i] = 1; res[i] = rig--; a--; }
                else cur[i] = 0;
            else if (b > 0) { cur[i] = -1; res[i] = lef++; b--; }
                 else cur[i] = 0;
            mx = !mx;
        }
        int pnt = 0;
        while (pnt < n && cur[pnt] == 0) pnt++;
        if (pnt >= n || cur[pnt] == 1)
            for (int i = 0; i < pnt; i++)
                res[i] = lef++;
        else for (int i = 0; i < pnt; i++)
                res[i] = rig--;
        pnt = n - 1;
        while (pnt >= 0 && cur[pnt] == 0) pnt--;
        if (pnt >= 0)
            if (cur[pnt] == 1)
                for (int i = pnt + 1; i < n; i++)
                    res[i] = rig--;
            else for (int i = pnt + 1; i < n; i++)
                    res[i] = lef++;
        for (int i = 0; i < n; i++)
            printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}