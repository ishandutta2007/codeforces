#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, s;
int a[Maxn];
int b[Maxn];

int main()
{
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    if (a[1] != 1) { printf("NO\n"); return 0; }
    if (a[s] == 1) { printf("YES\n"); return 0; }
    if (b[s] != 1) { printf("NO\n"); return 0; }
    for (int i = s; i <= n; i++)
        if (a[i] == 1 && b[i] == 1) { printf("YES\n"); return 0; }
    printf("NO\n");
    return 0;
}