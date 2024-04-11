#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn], b[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; i++)
            printf("%d%c", a[i], i + 1 < n? ' ': '\n');
        for (int i = 0; i < n; i++)
            printf("%d%c", b[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}