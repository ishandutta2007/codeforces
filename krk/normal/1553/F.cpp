#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n;
ll cnt[Maxn];
ll val[Maxn];

void Add(ll BIT[], int x, ll val)
{
    for (int i = x; i < Maxn; i += i & -i)
        BIT[i] += val;
}

ll Get(ll BIT[], int x)
{
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    scanf("%d", &n);
    ll res = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        res += sum + ll(i) * a;
        sum += a;
        res -= Get(val, a);
        for (int cur = a; cur < Maxn; cur += a) {
            int to = min(Maxn, cur + a) - 1;
            res -= (Get(cnt, to) - Get(cnt, cur - 1)) * cur;
            Add(val, cur, cur);
            Add(val, to + 1, -cur);
        }
        Add(cnt, a, 1);
        printf("%I64d%c", res, i + 1 < n? ' ': '\n');
    }
    return 0;
}