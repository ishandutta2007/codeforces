#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n, k;
int a[Maxn];
int res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        int cand = 0;
        for (int j = 0; j < n; j++) if ((i - j) % k != 0)
            cand += a[j];
        res = max(res, abs(cand));
    }
    printf("%d\n", res);
    return 0;
}