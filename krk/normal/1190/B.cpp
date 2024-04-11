#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i + 2 < n; i++)
        if (a[i] == a[i + 1] && a[i] == a[i + 2]) { printf("cslnb\n"); return 0; }
    int got = 0;
    for (int i = 0; i + 1 < n; i++)
        if (a[i] == a[i + 1] && (a[i] == 0 || i > 0 && a[i - 1] == a[i] - 1))
            { printf("cslnb\n"); return 0; }
        else if (a[i] == a[i + 1]) got++;
    if (got > 1) { printf("cslnb\n"); return 0; }
    ll res = 0;
    for (int i = 0; i < n; i++)
        if (i > a[i]) { printf("cslnb\n"); return 0; }
        else res += a[i] - i;
    if (res % 2) printf("sjfnb\n");
    else printf("cslnb\n");
    return 0;
}