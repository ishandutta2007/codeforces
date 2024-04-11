#include <bits/stdc++.h>
using namespace std;

int T;
int n, x, y;

void Solve(int n, int x, int y)
{
    if (x > y) swap(x, y);
    if (x != 0) { printf("-1\n"); return; }
    if (y == 0 || (n - 1) % y) { printf("-1\n"); return; }
    bool pr = false;
    for (int i = 2; i <= n; i += y)
        for (int j = 0; j < y; j++) {
            if (pr) printf(" ");
            else pr = true;
            printf("%d", i);
        }
    printf("\n");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &x, &y);
        Solve(n, x, y);
    }
    return 0;
}