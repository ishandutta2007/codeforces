#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 200005;
const ll Inf = 9000000000000000000ll;

int n;
ll a[Maxn];
llll val[Maxn];

int main()
{
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n; i++)
        val[i] = llll(a[i], sum - a[i]);
    sort(val, val + n);
    int m; scanf("%d", &m);
    while (m--) {
        ll x, y; scanf("%I64d %I64d", &x, &y);
        int ind = lower_bound(val, val + n, llll(x, 0ll)) - val;
        ll res1 = Inf;
        ll res2 = Inf;
        if (ind < n) res1 = max(0ll, y - val[ind].second);
        if (ind > 0) {
            ind--;
            res2 = max(0ll, y - val[ind].second) + max(0ll, x - val[ind].first);
        }
        printf("%I64d\n", min(res1, res2));
    }
    return 0;
}