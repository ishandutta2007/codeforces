#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n;
ll tot;
ll win[Maxn];
ll sum[Maxn];
int lim;

void gcd(ll a, ll &x, ll b, ll &y, ll &g)
{
    if (a == 0) { x = 0; y = 1; g = b; }
    else {
        ll xx, yy;
        gcd(b % a, xx, a, yy, g);
        x = yy - b / a * xx;
        y = xx;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        tot += a;
        win[i] = b - a;
    }
    sort(win, win + n);
    for (int i = n - 1; i >= 0; i--)
        sum[i] = win[i] + sum[i + 1];
    for (int i = 0; i < n; i++)
        if (win[i] < 0) lim = i + 1;
    int m; scanf("%d", &m);
    while (m--) {
        int r, b; scanf("%d %d", &r, &b);
        ll x, y, g; gcd(r, x, b, y, g);
        if (n % g) { printf("-1\n"); continue; }
        x *= (n / g); y *= (n / g);
        ll res = -1;
        if (x * r <= lim) {
            ll tk = (lim - x * r) / (ll(r) * (b / g));
            x += tk * (b / g);
        } else {
            ll tk = (x * r - lim) / (ll(r) * (b / g)) + 1;
            x -= tk * (b / g);
        }
        if (x * r >= 0) res = max(res, tot + sum[x * r]);
        x += b / g;
        if (x * r <= n) res = max(res, tot + sum[x * r]);
        printf("%I64d\n", res);
    }
    return 0;
}