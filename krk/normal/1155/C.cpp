#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n, m;
ll x[Maxn];
ll p[Maxn];

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d %d", &n, &m);
    ll g = 0;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &x[i]);
        if (i) g = gcd(g, x[i] - x[i - 1]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%I64d", &p[i]);
        if (g % p[i] == 0) {
            printf("YES\n");
            printf("%I64d %d\n", x[0], i + 1);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}