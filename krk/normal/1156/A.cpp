#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int res = 0;
    for (int i = 1; i < n; i++)
        if (a[i - 1] == a[i]) { printf("Infinite\n"); return 0; }
        else if (a[i - 1] == 1)
                if (a[i] == 2) res += (i >= 2 && a[i - 2] == 3)? 2: 3;
                else res += 4;
             else if (a[i - 1] == 2)
                if (a[i] == 1) res += 3;
                else { printf("Infinite\n"); return 0; }
             else if (a[i - 1] == 3)
                if (a[i] == 1) res += 4;
                else { printf("Infinite\n"); return 0; }
    printf("Finite\n");
    printf("%d\n", res);
    return 0;
}