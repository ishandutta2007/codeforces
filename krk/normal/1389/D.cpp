#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;

int T;
int n, k;
int l1, r1;
int l2, r2;
ll zers, ones, sam;
ll res;

ll Solve(int n)
{
    ll res = zers * ll(n);
    ll lft = k;
    ll tk = min(ones * ll(n), lft);
    res += tk; lft -= tk;
    res += 2ll * lft;
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%d %d", &l1, &r1);
        scanf("%d %d", &l2, &r2);
        res = Inf;
        sam = 0;
        if (r1 <= l2) zers = l2 - r1;
        else if (r2 <= l1) zers = l1 - r2;
        else {
            zers = 0;
            ll lef = max(l1, l2), rig = min(r1, r2);
            sam = rig - lef;
        }
        ones = r1 - l1 + r2 - l2 - 2 * sam;
        ones += zers;
        if (k <= ll(sam) * n) {
            printf("0\n");
            continue;
        }
        k -= sam * n;
        for (int i = 1; i <= n; i++)
            res = min(res, Solve(i));
        printf("%I64d\n", res);
    }
    return 0;
}