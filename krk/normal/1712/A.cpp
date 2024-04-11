#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, k;
int p[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &p[i]);
        int res = 0;
        for (int i = 0; i < k; i++)
            res += p[i] > k;
        printf("%d\n", res);
    }
    return 0;
}