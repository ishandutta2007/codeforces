#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
int pos[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]); pos[a[i]] = i;
    }
    for (int i = n; i > 0; i--) {
        int p = pos[i];
        res[p] = -1;
        for (int np = p; np <= n; np += i)
            if (a[p] < a[np]) res[p] = max(res[p], -res[np]);
        for (int np = p; np > 0; np -= i)
            if (a[p] < a[np]) res[p] = max(res[p], -res[np]);
    }
    for (int i = 1; i <= n; i++)
        printf("%c", res[i] > 0? 'A': 'B');
    printf("\n");
    return 0;
}