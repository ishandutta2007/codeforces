#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, k;
int a[Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i - 1] > 0) {
            int nd = (a[i - 1] - 1) / k + 1;
            res += nd;
            int lft = ll(nd) * k - a[i - 1];
            int tk = min(lft, a[i]);
            a[i] -= tk;
        }
        if (i == n - 1 && a[i] > 0) {
            int nd = (a[i] - 1) / k + 1;
            res += nd;
        }
    }
    printf("%I64d\n", res);
    return 0;
}