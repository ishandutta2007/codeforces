#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int t;
int n;
int a[Maxn];

void Solve()
{
    for (int i = 1; i < n; i++)
        if (abs(a[i] - a[i + 1]) > 1) {
            printf("YES\n");
            printf("%d %d\n", i, i + 1);
            return;
        }
    printf("NO\n");
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        Solve();
    }
    return 0;
}