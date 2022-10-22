#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, r;
int a[Maxn];

int main()
{
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int pnt = 0;
    int res = 0;
    while (pnt < n) {
        res++;
        int lst = -1;
        for (int i = 0; i < n && i - pnt < r; i++) if (i + r > pnt)
            if (a[i] == 1) lst = i;
        if (lst == -1) { printf("-1\n"); return 0; }
        pnt = lst + r;
    }
    printf("%d\n", res);
    return 0;
}