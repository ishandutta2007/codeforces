#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];
ll BIT[Maxn];
ll cur;

void Add(int ind, ll val)
{
    for (int i = ind; i < Maxn; i += i & -i)
        BIT[i] += val;
}

ll Get(int ind)
{
    ll res = 0;
    for (int i = ind; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

ll Solve()
{
    ll x = (Get(1) - cur) / 2;
    return max(cur + x, Get(1) - x);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        Add(i, a[i]);
        Add(i + 1, -a[i]);
        if (i > 1 && a[i] > a[i - 1]) cur += a[i] - a[i - 1];
    }
    printf("%I64d\n", Solve());
    int q; scanf("%d", &q);
    while (q--) {
        int l, r, x; scanf("%d %d %d", &l, &r, &x);
        if (l > 1) cur -= max(0ll, Get(l) - Get(l - 1));
        if (r < n) cur -= max(0ll, Get(r + 1) - Get(r));
        Add(l, x);
        Add(r + 1, -x);
        if (l > 1) cur += max(0ll, Get(l) - Get(l - 1));
        if (r < n) cur += max(0ll, Get(r + 1) - Get(r));
        printf("%I64d\n", Solve());
    }
    return 0;
}