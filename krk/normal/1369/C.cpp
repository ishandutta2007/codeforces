#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
int a[Maxn];
int w[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        for (int i = 0; i < k; i++)
            scanf("%d", &w[i]);
        sort(w, w + k);
        long long res = 0;
        for (int i = 0; i < k; i++)
            res += a[n - 1 - i];
        int pnt = 0;
        int ones = 0;
        for (int i = 0; i < k; i++)
            if (w[k - 1 - i] == 1) ones++;
            else {
                res += a[pnt];
                pnt += w[k - 1 - i] - 1;
            }
        for (int i = 0; i < ones; i++)
            res += a[n - 1 - i];
        printf("%I64d\n", res);
    }
    return 0;
}