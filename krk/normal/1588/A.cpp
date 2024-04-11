#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];
int b[Maxn];

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
        bool ok = true;
        for (int i = 0; i < n && ok; i++)
            ok = a[i] == b[i] || a[i] + 1 == b[i];
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}