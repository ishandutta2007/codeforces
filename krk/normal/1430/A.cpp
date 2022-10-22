#include <bits/stdc++.h>
using namespace std;

int T;
int n;

void Solve(int n)
{
    for (int i = 1; 3 * i <= n; i++) {
        int lft = n - 3 * i;
        if (lft % 2) continue;
        lft /= 2;
        if (lft <= 2 * i) {
            int all = i;
            int tk7 = min(all, lft / 2);
            all -= tk7; lft -= 2 * tk7;
            int tk5 = min(all, lft);
            all -= tk5; lft -= tk5;
            int tk3 = all;
            printf("%d %d %d\n", tk3, tk5, tk7);
            return;
        }
    }
    printf("-1\n");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        Solve(n);
    }
    return 0;
}