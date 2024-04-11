#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn], ina[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ina[a[i]] = i;
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", ina[n + 1 - i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}