#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i + 1 < n; i++) if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1) {
        res++;
        a[i + 1] = 0;
    }
    printf("%d\n", res);
    return 0;
}