#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", n + 1);
    int add = 0;
    for (int i = n - 1; i >= 0; i--) {
        a[i] = (a[i] + add) % n;
        int gv = (i - a[i] + n) % n;
        printf("1 %d %d\n", i + 1, gv);
        add = (add + gv) % n;
    }
    printf("2 %d %d\n", n, n);
    return 0;
}