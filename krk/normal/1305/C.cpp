#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m;
int a[Maxn];
int res = 1;

int main()
{
    scanf("%d %d", &n, &m);
    if (n > 1000) { printf("0\n"); return 0; }
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            res = ll(res) * (a[j] - a[i]) % m;
    printf("%d\n", res);
    return 0;
}