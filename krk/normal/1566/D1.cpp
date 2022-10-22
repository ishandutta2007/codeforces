#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;

int T;
int n, m;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int res = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i]);
            for (int j = 0; j < i; j++)
                res += a[j] < a[i];
        }
        printf("%d\n", res);
    }
    return 0;
}