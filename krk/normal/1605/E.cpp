#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 200005;
const int Maxm = 1000005;
const int Maxs = 4194304;

int n;
llll a[Maxn];
llll b[Maxn];
llll nd[Maxn];
llll st[Maxs];

llll Add(const llll &a, const llll &b)
{
    return llll(a.first + b.first, a.second + b.second);
}

llll Sub(const llll &a, const llll &b)
{
    return llll(a.first - b.first, a.second - b.second);
}

llll Rev(const llll &a)
{
    return llll(-a.first, -a.second);
}

void Add(int v, int l, int r, int a, int b, const llll &p)
{
    if (l == a && r == b) st[v] = Add(st[v], p);
    else {
        int m = l + r >> 1;
        if (a <= m) Add(2 * v, l, m, a, min(m, b), p);
        if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, p);
    }
}

ll Get(int v, int l, int r, int x)
{
    ll res = st[v].first * ll(x) + st[v].second;
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) res += Get(2 * v, l, m, x);
        else res += Get(2 * v + 1, m + 1, r, x);
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &a[i].second);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &b[i].second);
        if (i == 1) b[i] = llll(1ll, 0ll);
    }
    for (int i = 1; i <= n; i++) {
        nd[i] = Sub(b[i], a[i]);
        if (nd[i].first >= 0) {
            int lef = 0, rig = Maxm;
            while (lef <= rig) {
                int mid = lef + rig >> 1;
                if (nd[i].first * ll(mid) + nd[i].second >= 0)
                    rig = mid - 1;
                else lef = mid + 1;
            }
            if (lef <= Maxm) Add(1, 0, Maxm, lef, Maxm, nd[i]);
            if (rig >= 0) Add(1, 0, Maxm, 0, rig, Rev(nd[i]));
        } else {
            int lef = 0, rig = Maxm;
            while (lef <= rig) {
                int mid = lef + rig >> 1;
                if (nd[i].first * ll(mid) + nd[i].second >= 0)
                    lef = mid + 1;
                else rig = mid - 1;
            }
            if (rig >= 0) Add(1, 0, Maxm, 0, rig, nd[i]);
            if (lef <= Maxm) Add(1, 0, Maxm, lef, Maxm, Rev(nd[i]));
        }
        for (int j = i + i; j <= n; j += i)
            a[j] = Add(a[j], nd[i]);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        printf("%I64d\n", Get(1, 0, Maxm, x));
    }
    return 0;
}