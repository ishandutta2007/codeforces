#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int x[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d\n", &n);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
            cur |= x[i];
            res[i] = cur ^ x[i];
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}