#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];
int b[Maxn];
int c[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &c[i]);
        for (int i = 0; i < n; i += 2)
            res[i] = a[i];
        if (n % 2 == 1)
            if (res[0] == res[n - 1]) res[n - 1] = b[n - 1];
        for (int i = 1; i < n; i += 2) {
            int f = res[i - 1];
            int s = res[(i + 1) % n];
            if (a[i] != f && a[i] != s)
                res[i] = a[i];
            else if (b[i] != f && b[i] != s)
                res[i] = b[i];
            else res[i] = c[i];
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}