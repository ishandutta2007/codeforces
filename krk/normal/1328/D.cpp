#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int res[Maxn];

void Solve()
{
    int sam = -1, dif = 0;
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        if (a[i] == a[ni]) sam = ni;
        else dif++;
    }
    if (dif == 0) {
        printf("1\n");
        for (int i = 0; i < n; i++)
            printf("1%c", i + 1 < n? ' ': '\n');
        return;
    }
    if (sam == -1 && n % 2 != 0) {
        printf("3\n");
        for (int i = 0; i + 1 < n; i++)
            printf("%d ", i % 2 + 1);
        printf("3\n");
        return;
    }
    if (sam == -1) sam = 0;
    printf("2\n");
    for (int i = 0; i < n; i++) {
        int cur = (i + sam) % n;
        res[cur] = i % 2 + 1;
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        Solve();
    }
    return 0;
}