#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;

struct node {
    int sum, mn, mx;
    node(): sum(0), mn(0), mx(0) {}
};

int n;
int a[Maxn];
vector <int> V[Maxn];
node st[Maxm];
int res[Maxn];

node Union(const node &a, const node &b)
{
    node c;
    c.sum = a.sum + b.sum;
    c.mn = min(a.mn, a.sum + b.mn);
    c.mx = max(a.mx, a.sum + b.mx);
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r)
        st[v].sum = st[v].mn = st[v].mx = l == 0? 0: 1;
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Set(int v, int l, int r, int x, int val)
{
    if (l == r) st[v].sum = st[v].mn = st[v].mx = val;
    else {
        int m = l + r >> 1;
        if (x <= m) Set(2 * v, l, m, x, val);
        else Set(2 * v + 1, m + 1, r, x, val);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

int Get(int v, int l, int r, int a, int b, int pref, bool getMax)
{
    if (l == a && r == b) return pref + (getMax? st[v].mx: st[v].mn);
    else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b, pref, getMax);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b, pref + st[2 * v].sum, getMax);
        int res1 = Get(2 * v, l, m, a, m, pref, getMax);
        int res2 = Get(2 * v + 1, m + 1, r, m + 1, b, pref + st[2 * v].sum, getMax);
        return getMax? max(res1, res2): min(res1, res2);
    } 
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        V[a[i]].push_back(i);
    }
    Create(1, 0, n);
    for (int v = 1; v <= n; v++) {
        for (int j = 0; j < V[v].size(); j++) {
            int i = V[v][j];
            res[i] = max(res[i], (Get(1, 0, n, i, n, 0, true) - Get(1, 0, n, 0, i - 1, 0, false)) / 2);
        }
        for (int j = 0; j < V[v].size(); j++) {
            int i = V[v][j];
            Set(1, 0, n, i, -1);
        }
        for (int j = 0; j < V[v].size(); j++) {
            int i = V[v][j];
            res[i] = max(res[i], (-(Get(1, 0, n, i, n, 0, false) - Get(1, 0, n, 0, i - 1, 0, true)) - 1) / 2);
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}