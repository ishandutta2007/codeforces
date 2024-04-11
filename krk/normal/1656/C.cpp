#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

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
        sort(a, a + n);
        int pnt = 0;
        bool haszer = a[pnt] == 0;
        while (pnt < n && a[pnt] == 0) pnt++;
        bool hasone = pnt < n && a[pnt] == 1;
        while (pnt < n && a[pnt] == 1) pnt++;
        if (haszer && hasone) { printf("NO\n"); continue; }
        if (!hasone) { printf("YES\n"); continue; }
        bool fall = false;
        for (int i = pnt; i < n; i++)
            if (a[i] == 2 || i + 1 < n && a[i] + 1 == a[i + 1]) fall = true;
        printf("%s\n", fall? "NO": "YES");
    }
    return 0;
}