#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 105;

int T;
int n;
ll a[Maxn];

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ll getD(int wh)
{
    ll g = 0;
    for (int i = 0; i < n; i++) if (i % 2 == wh)
        g = gcd(g, a[i]);
    for (int i = 0; i < n; i++) if (i % 2 != wh)
        if (a[i] % g == 0) return 0;
    return g;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%I64d", &a[i]);
        ll d = max(getD(0), getD(1));
        printf("%I64d\n", d);
    }  
    return 0;
}