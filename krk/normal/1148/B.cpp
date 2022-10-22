#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 200005;

int n, m, ta, tb, k;
int a[Maxn], b[Maxn];
ll res = 0;

int main()
{
    scanf("%d %d %d %d %d", &n, &m, &ta, &tb, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i <= min(k, n); i++)
        if (i < n) {
            int f = lower_bound(b, b + m, a[i] + ta) - b + k - i;
            if (f < m) res = max(res, ll(b[f]) + ll(tb));
            else res = Inf;
        } else res = Inf;
    if (res >= Inf) cout << "-1\n";
    else cout << res << endl;
    return 0;
}