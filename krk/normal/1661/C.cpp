#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int T;
int n;
int h[Maxn];

ll Solve(int x)
{
    ll ones = 0, twos = 0;
    for (int i = 0; i < n; i++) {
        ll got = x - h[i];
        twos += got / 2;
        ones += got % 2;
    }
    ll res;
    if (ones <= twos) {
        ll nd = ones + 2 * twos;
        res = nd / 3 * 2 + nd % 3;
    } else {
        res = twos * 2;
        ones -= twos;
        res += ones * 2 - 1;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &h[i]);
        sort(h, h + n);
        ll res = 1000000000000000000ll;
        for (int i = 0; i <= 3; i++)
            res = min(res, Solve(h[n - 1] + i));
        printf("%I64d\n", res);
    }
    return 0;
}