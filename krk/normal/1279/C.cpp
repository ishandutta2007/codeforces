#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int t;
int n, m;
int a[Maxn];
int ind[Maxn];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ind[a[i]] = i;
        }
        ll res = 0;
        int mx = 0, tk = 0;
        for (int i = 1; i <= m; i++) {
            int b; scanf("%d", &b);
            b = ind[b];
            if (b <= mx) res++;
            else {
                res += 2ll * (b - 1 - tk) + 1;
                mx = b;
            }
            tk++;
        }
        printf("%I64d\n", res);
    }
    return 0;
}