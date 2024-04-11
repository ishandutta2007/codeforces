#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int sam[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int res = 0;
        for (int i = 0; i < n; i++) {
            sam[i] = (i > 0 && a[i] == a[i - 1]? sam[i - 1] + 1: 1);
            if (i + 1 >= n || a[i] == a[i + 1]) res = max(res, sam[i]);
            else {
                int cur = sam[i] + 1;
                int A = a[i], B = a[i + 1];
                while (true) {
                    int ind = lower_bound(a, a + n, 2 * B - A) - a;
                    if (ind >= n) break;
                    cur++;
                    B = a[ind];
                }
                res = max(res, cur);
            }
        }
        printf("%d\n", n - res);
    }
    return 0;
}