#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > a[mx]) mx = i;
    }
    for (int i = mx - 1; i >= 0; i--)
        if (a[i] > a[i + 1]) { printf("NO\n"); return 0; }
    for (int i = mx + 1; i < n; i++)
        if (a[i] > a[i - 1]) { printf("NO\n"); return 0; }
    printf("YES\n");
    return 0;
}