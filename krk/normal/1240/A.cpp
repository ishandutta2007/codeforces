#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int q;
int n;
int p[Maxn];
int x, a;
int y, b;
ll k;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

bool Ok(int m)
{
    ll lcm = ll(a) / gcd(a, b) * b;
    int tot = m / lcm;
    int tkx = m / a - tot;
    int tky = m / b - tot;
    ll res = 0;
    for (int i = 1; i <= tot; i++)
        res += ll(p[n - i] / 100) * (x + y);
    for (int i = 1; i <= tky; i++)
        res += ll(p[n - tot - i] / 100) * y;
    for (int i = 1; i <= tkx; i++)
        res += ll(p[n - tot - tky - i] / 100) * x;
    return res >= k;
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &p[i]);
        sort(p, p + n);
        scanf("%d %d", &x, &a);
        scanf("%d %d", &y, &b);
        if (x > y) { swap(x, y); swap(a, b); }
        scanf("%I64d", &k);
        int lef = 0, rig = n;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Ok(mid)) rig = mid - 1;
            else lef = mid + 1;
        }
        rig++;
        if (rig > n) printf("-1\n");
        else printf("%d\n", rig);
    }
    return 0;
}