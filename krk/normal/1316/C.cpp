#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int n, m, p;
int a[Maxn], b[Maxn];

int main()
{
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    int i = 0, j = 0;
    while (a[i] % p == 0) i++;
    while (b[j] % p == 0) j++;
    printf("%d\n", i + j);
    return 0;
}