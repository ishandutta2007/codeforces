#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        for (int i = n - 1; i >= 0; i--)
            printf("%d%c", a[i], i - 1 >= 0? ' ': '\n');
    }
    return 0;
}