#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 300005;
const int Maxm = 2097152;

struct node {
    ll mx[2], mn[2];
    node() {
        mx[0] = mx[1] = -Inf;
        mn[0] = mn[1] = Inf;
    }
};

int T;
int n, q;
int a[Maxn];
node st[Maxm];

node Union(const node &a, const node &b)
{
    node res;
    res.mx[0] = max(a.mx[0] + b.mx[0], a.mx[1] - b.mn[1]);
    res.mx[1] = max(a.mx[0] + b.mx[1], a.mx[1] - b.mn[0]);
    res.mn[0] = min(a.mn[0] + b.mn[0], a.mn[1] - b.mx[1]);
    res.mn[1] = min(a.mn[0] + b.mn[1], a.mn[1] - b.mx[0]);
    return res;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].mx[0] = st[v].mn[0] = 0;
        st[v].mx[1] = st[v].mn[1] = a[l];
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(int v, int l, int r, int x)
{
    if (l == r) {
        st[v].mx[0] = st[v].mn[0] = 0;
        st[v].mx[1] = st[v].mn[1] = a[l];
    } else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x);
        else Update(2 * v + 1, m + 1, r, x);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

ll Get()
{
    return max(st[1].mx[0], st[1].mx[1]);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        Create(1, 1, n);
        printf("%I64d\n", Get());
        while (q--) {
            int l, r; scanf("%d %d", &l, &r);
            swap(a[l], a[r]);
            Update(1, 1, n, l);
            Update(1, 1, n, r);
            printf("%I64d\n", Get());
        }
    }
    return 0;
}