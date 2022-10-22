#include <bits/stdc++.h>
using namespace std;

const int Maxn = 15;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < 1 << n; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++)
            if (i & 1 << j) cur += a[j];
            else cur -= a[j];
        if (cur % 360 == 0) { printf("YES\n"); return 0; }
    }
    printf("NO\n");
    return 0;
}