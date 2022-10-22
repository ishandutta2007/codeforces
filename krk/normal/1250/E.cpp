#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
int m;
int a[Maxn];

bool Check(int x)
{
    int lft = m;
    for (int i = 0; i < n; i++)
        if (a[i] > x) return false;
        else lft -= (x - a[i]);
    return lft <= 0;
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int x = 1;
    while (!Check(x)) x++;
    printf("%d %d\n", x, a[n - 1] + m);
    return 0;
}