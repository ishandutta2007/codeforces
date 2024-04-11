#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            if (i % 2 == 0 && a[i] < 0 ||
                i % 2 == 1 && a[i] > 0) a[i] = -a[i];
        for (int i = 0; i < n; i++)
            printf("%d%c", a[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}