#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

int T;
int n;
int h[Maxn];
ll lef[Maxn], rig[Maxn];

ll Get(int ind)
{
    return max(0, max(h[ind - 1], h[ind + 1]) + 1 - h[ind]);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        if (n % 2) {
            ll res = 0;
            for (int i = 2; i <= n; i += 2)
                res += Get(i);
            printf("%I64d\n", res);
            continue;
        }
        for (int i = 2; i < n; i += 2)
            lef[i] = lef[i - 2] + Get(i);
        rig[n + 1] = 0;
        for (int i = n - 1; i > 1; i -= 2)
            rig[i] = rig[i + 2] + Get(i);
        ll res = Inf;
        for (int i = 0; i < n; i += 2)
            res = min(res, lef[i] + rig[i + 3]);
        printf("%I64d\n", res);
    }
    return 0;
}