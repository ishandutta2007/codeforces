#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
int en;
int a[Maxn];

int askEnd(int x)
{
    printf("?");
    for (int i = 0; i < n - 1; i++)
        printf(" 1");
    printf(" %d\n", 1 + x); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int Which(int x)
{
    if (x == en) return n;
    int a, b;
    if (x < en) {
        a = 1 + en - x;
        b = 1;
    } else {
        a = 1;
        b = x - en + 1;
    }
    printf("?");
    for (int i = 0; i < n - 1; i++)
        printf(" %d", a);
    printf(" %d\n", b); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &n);
    int cur = n;
    while (cur > 1 && askEnd(n - (cur - 1)) > 0) cur--;
    en = cur;
    for (int i = 1; i <= n; i++)
        a[Which(i)] = i;
    printf("!");
    for (int i = 1; i <= n; i++)
        printf(" %d", a[i]);
    printf("\n"); fflush(stdout);
    return 0;
}