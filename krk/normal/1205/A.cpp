#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int res[Maxn];

int main()
{
    scanf("%d", &n);
    if (n % 2 == 0) { printf("NO\n"); return 0; }
    for (int i = 0; i < n; i++)
        if (i % 2 == 0) { res[i] = 2 * i + 1; res[n + i] = 2 * i + 2; }
        else { res[i] = 2 * i + 2; res[n + i] = 2 * i + 1; }
    printf("YES\n");
    for (int i = 0; i < 2 * n; i++)
        printf("%d%c", res[i], i + 1 < 2 * n? ' ': '\n');
    return 0;
}