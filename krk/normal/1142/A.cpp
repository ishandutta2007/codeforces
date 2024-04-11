#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000;

int n, k;
int a, b;
ll all;
ll mn = Inf, mx = -Inf;

void Upd(ll x)
{
    mn = min(mn, x);
    mx = max(mx, x);
}

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

bool Check(ll len)
{
    Upd(all / gcd(all, len));
}

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%d %d", &a, &b);
    all = ll(n) * k;
    for (int i = 0; i < n; i++) {
        ll my = ll(i) * k + b;
        if (my >= a) Check(my - a);
        else Check(all + my - a);
        my = ll(i) * k - b;
        if (my >= a) Check(my - a);
        else Check(all + my - a);
    }
    printf("%I64d %I64d\n", mn, mx);
    return 0;
}