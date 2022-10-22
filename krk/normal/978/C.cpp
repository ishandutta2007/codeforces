#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m;
ll a[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        a[i] += a[i - 1];
    }
    while (m--) {
        ll b; scanf("%I64d", &b);
        int ind = lower_bound(a, a + n + 1, b) - a;
        printf("%d %I64d\n", ind, b - a[ind - 1]);
    }
    return 0;
}