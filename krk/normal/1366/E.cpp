#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;

int n, m;
int a[Maxn];
int b[Maxn];
int res = 1;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = n - 2; i >= 0; i--)
        a[i] = min(a[i], a[i + 1]);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        int lef = lower_bound(a, a + n, b[i]) - a;
        int rig = upper_bound(a, a + n, b[i]) - a - 1;
        if (lef > rig || i == 0 && lef > 0) res = 0;
        else if (i > 0) res = ll(res) * (rig - lef + 1) % mod;
    }
    cout << res << endl;
    return 0;
}