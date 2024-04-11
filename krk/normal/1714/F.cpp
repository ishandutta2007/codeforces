#include <bits/stdc++.h>
using namespace std;

int T;
int n, d12, d23, d31;

void Print(int m, int len, int en, int &pnt)
{
    int cur = m;
    if (len > 0) {
        for (int i = 0; i < len - 1; i++) {
            printf("%d %d\n", cur, pnt);
            cur = pnt++;
        }
        printf("%d %d\n", cur, en);
    }
}

void Solve()
{
    for (int x = 0; x <= n; x++) {
        int y = d12 - x;
        if (y < 0) continue;
        int z = d31 - x;
        if (z < 0) continue;
        if (y + z != d23) continue;
        if (1 + x + y + z > n) continue;
        if (int(x == 0) + int(y == 0) + int(z == 0) >= 2) continue;
        printf("YES\n");
        int m;
        if (x == 0) m = 1;
        else if (y == 0) m = 2;
        else if (z == 0) m = 3;
        else m = 4;
        int pnt = max(m + 1, 4);
        Print(m, x, 1, pnt);
        Print(m, y, 2, pnt);
        Print(m, z, 3, pnt);
        while (pnt <= n)
            printf("3 %d\n", pnt++);
        return;
    }
    printf("NO\n");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &d12, &d23, &d31);
        Solve();
    }
    return 0;
}