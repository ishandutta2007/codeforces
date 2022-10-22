#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 10005;
const ll Inf = 2000000000000000000LL;

int n, c;
int a[Maxn], b[Maxn];
ll l, r;
ll mn = Inf, mx = 0;

ll Mult(ll a, ll b)
{
    if (a > Inf / b) return Inf;
    return a * b;
}

ll Status(ll x)
{
    ll lft = c - n;
    for (int i = 0; i < n && lft >= 0; i++)
        if (Mult(a[i], x) / b[i] > lft) return -1;
        else lft -= a[i] * x / b[i];
    return lft;
}

int main()
{
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
    if (Status(Inf) == 0LL) { printf("-1\n"); return 0; }
    l = 1, r = Inf;
    while (l <= r) {
        ll mid = l + r >> 1LL;
        int st = Status(mid);
        if (st < 0) r = mid - 1LL;
        else if (st == 0) { mn = min(mn, mid); mx = max(mx, mid); r = mid - 1LL; }
        else l = mid + 1LL;
    }
    l = 1, r = Inf;
    while (l <= r) {
        ll mid = l + r >> 1LL;
        int st = Status(mid);
        if (st < 0) r = mid - 1LL;
        else if (st == 0) { mn = min(mn, mid); mx = max(mx, mid); l = mid + 1LL; }
        else l = mid + 1LL;
    }
    if (mn > mx) printf("0\n");
    else printf("%I64d\n", mx - mn + 1LL);
    return 0;
}