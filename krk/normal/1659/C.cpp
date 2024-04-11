#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 4000000000000000000ll;
const int Maxn = 200005;

int T;
int n, a, b;
int x[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &a, &b);
        for (int i = 1; i <= n; i++)
            scanf("%d", &x[i]);
        ll res = Inf;
        ll cur = 0;
        for (int i = n; i > 0; i--) {
            res = min(res, cur + ll(x[i]) * a + ll(x[i]) * b - ll(n - i) * b * x[i]);
            cur += ll(x[i]) * b;
        }
        res = min(res, cur);
        printf("%I64d\n", res);
    }
    return 0;
}