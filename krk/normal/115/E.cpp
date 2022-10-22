#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 600000;

struct node {
    int l, r;
    ll mx, bon;
} t[Maxm];

int n, m;
int cost[Maxn];
vector <int> st[Maxn], in[Maxn];

void Create(int v, int l, int r)
{
    t[v].l = l, t[v].r = r;
    t[v].mx = t[v].bon = 0;
    if (l == r) return;
    int mid = l + r >> 1;
    Create(2 * v, l, mid); Create(2 * v + 1, mid + 1, r);
}

ll getBest(int v, int l, int r)
{
    if (t[v].l == l && t[v].r == r) return t[v].mx + t[v].bon;
    int mid = t[v].l + t[v].r >> 1;
    if (r <= mid) return getBest(2 * v, l, r) + t[v].bon;
    if (mid < l) return getBest(2 * v + 1, l, r) + t[v].bon;
    return max(getBest(2 * v, l, mid), getBest(2 * v + 1, mid + 1, r)) + t[v].bon;
}

void Insert(int v, int x, ll val)
{
    if (t[v].l == x && t[v].r == x) { t[v].mx = val; return; }
    int mid = t[v].l + t[v].r >> 1;
    if (x <= mid) Insert(2 * v, x, val);
    else Insert(2 * v + 1, x, val);
    t[v].mx = max(t[2 * v].mx + t[2 * v].bon, t[2 * v + 1].mx + t[2 * v + 1].bon);
}

void Update(int v, int l, int r, ll val)
{
    if (t[v].l == l && t[v].r == r) { t[v].bon += val; return; }
    int mid = t[v].l + t[v].r >> 1;
    if (l <= mid) Update(2 * v, l, min(mid, r), val);
    if (mid < r) Update(2 * v + 1, max(mid + 1, l), r, val);
    t[v].mx = max(t[2 * v].mx + t[2 * v].bon, t[2 * v + 1].mx + t[2 * v + 1].bon);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &cost[i]);
    while (m--) {
        int l, r, p; scanf("%d %d %d", &l, &r, &p);
        st[r].push_back(l); in[r].push_back(p);
    }
    Create(1, 0, n);
    for (int i = 1, beg = n; i <= n; i++, beg--) {
        Insert(1, beg - 1, getBest(1, beg, n));
        Update(1, beg, n, -cost[i]);
        for (int j = 0; j < st[i].size(); j++)
            Update(1, beg + i - st[i][j], n, in[i][j]);
    }
    printf("%I64d\n", getBest(1, 0, n));
    return 0;
}