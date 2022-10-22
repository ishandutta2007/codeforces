#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

int T;
int n;
ll l, r;

ii getPar(ll x)
{
    int lef = 1, rig = n - 1;
    while (lef <= rig) {
        int m = lef + rig >> 1;
        ll sum = ll(n - 1 + n - m) * m / 2ll;
        if (x <= sum) rig = m - 1;
        else lef = m + 1;
    }
    if (lef >= n) return ii(1, 1);
    ll sum = ll(n - 1 + n - (lef - 1)) * (lef - 1) / 2ll;
    x -= sum;
    return ii(lef, lef + x);
}

int Get(ll x)
{
    ii g = getPar((x + 1) / 2ll);
    return x % 2? g.first: g.second;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %I64d %I64d", &n, &l, &r);
        for (ll x = l; x <= r; x++)
            printf("%d%c", Get(x), x + 1 <= r? ' ': '\n');
    }
    return 0;
}