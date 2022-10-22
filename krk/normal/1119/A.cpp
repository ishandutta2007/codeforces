#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n;
int c[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    int pnt = n - 1;
    while (c[0] == c[pnt]) pnt--;
    res = max(res, pnt);
    pnt = 0;
    while (c[pnt] == c[n - 1]) pnt++;
    res = max(res, n - 1 - pnt);
    printf("%d\n", res);
    return 0;
}