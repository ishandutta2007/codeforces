#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

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
        for (int i = n - 2; i >= 0; i -= 2)
            if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        bool ok = true;
        for (int i = 0; i + 1 < n; i++)
            if (a[i] > a[i + 1]) ok = false;
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}