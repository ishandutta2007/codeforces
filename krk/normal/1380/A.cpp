#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1004;

int T;
int n;
int a[Maxn];

void Solve()
{
    for (int i = 2; i < n; i++)
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            printf("YES\n");
            printf("%d %d %d\n", i - 1, i, i + 1);
            return;
        }
    printf("NO\n");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        Solve();
    }
    return 0;
}