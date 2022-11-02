#include <bits/stdc++.h>

using namespace std;

const int N = 150 * 1000 + 10;

int tree[4 * N], add[4 * N];
int n, len, h;
int a[N], b[N];

void build(int i, int l, int r)
{
    if (l == r)
    {
        tree[i] = l - len;
        add[i] = 0;
        return;
    }
    add[i] = 0;
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

int get(int i, int l, int r, int tl, int tr, int a)
{
    a += add[i];
    if (l == tl && r == tr)
        return tree[i] + a;
    int ml = N;
    int mr = N;
    int m = (tl + tr) / 2;
    if (l <= m)
        ml = get(2 * i + 1, l, min(r, m), tl, m, a);
    if (r > m)
        mr = get(2 * i + 2, max(m + 1, l), r, m + 1, tr, a);
    return min(ml, mr);
}

void put(int i, int l, int r, int tl, int tr, int x)
{
    if (l == tl && r == tr)
    {
        add[i] += x;
        return;
    }
    int m = (tl + tr) / 2;
    if (l <= m)
        put(2 * i + 1, l, min(r, m), tl, m, x);
    if (r > m)
        put(2 * i + 2, max(m + 1, l), r, m + 1, tr, x);
    tree[i] = min(get(2 * i + 1, 0, 0, 0, 0, 0), get(2 * i + 2, 0, 0, 0, 0, 0));
}

int f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("in.cpp", "r", stdin);
        freopen("out.cpp", "w", stdout);
    #endif

    cin >> n >> len >> h;
    for (int i = 0; i < len; i++)
    {
        cin >> b[i];
        b[i] = h - b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(b, b + len);
    for (int i = 0; i < n; i++)
    {
        f[i] = upper_bound(b, b + len, a[i]) - b;
        f[i]--;
    }
    build(0, 0, len - 1);
    for (int i = 0; i < len; i++)
        if (f[i] >= 0)
            put(0, 0, f[i], 0, len - 1, 1);
    int res = 0;
    if (get(0, 0, 0, 0, 0, 0) >= 0)
        res++;
    for (int l = 0, r = len; r < n; r++, l++)
    {
        if (f[l] >= 0)
            put(0, 0, f[l], 0, len - 1, -1);
        if (f[r] >= 0)
            put(0, 0, f[r], 0, len - 1, 1);
        if (get(0, 0, 0, 0, 0, 0) >= 0)
            res++;
        //cerr << l << " " << r << " " << res << endl;
    }

    cout << res;

    return 0;
}