#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int N = 100 * 1000 + 2;
vector<int> tr[4 * N + 10];
int L[4 * N + 10], R[4 * N + 10];
vector<int> atx[N];

void build(int pos, int l, int r)
{
    L[pos] = l;
    R[pos] = r;
    if (l == r)
    {
        tr[pos] = atx[l];
        return;
    }
    int m = (l + r) / 2, cl = 2 * pos + 1, cr = 2 * pos + 2;
    build(cl, l, m);
    build(cr, m + 1, r);
    tr[pos].resize(tr[cl].size() + tr[cr].size());
    merge(tr[cl].begin(), tr[cl].end(), tr[cr].begin(), tr[cr].end(), tr[pos].begin());
}

int getCnt(int pos, int l, int r, int yl, int yr)
{
    if (L[pos] == l && R[pos] == r)
    {
        int lo = lower_bound(tr[pos].begin(), tr[pos].end(), yl) - tr[pos].begin();
        int hi = upper_bound(tr[pos].begin(), tr[pos].end(), yr) - tr[pos].begin();
        return hi - lo;
    }
    int m = (R[pos] + L[pos]) / 2, cl = 2 * pos + 1, cr = 2 * pos + 2;
    int sl = 0, sr = 0;
    if (l <= m)
        sl = getCnt(cl, l, min(m, r), yl, yr);
    if (r > m)
        sr = getCnt(cr, max(m + 1, l), r, yl, yr);
    return sl + sr;
}

#define pii pair<int, int>
#define F first
#define S second

pii p[N];
map<int, int> mx, my;
int sx[N], sy[N];
int n;

bool cmp2(pii a, pii b)
{
    return a.S < b.S;
}

void init()
{
    fill(sx, sx + N, 0);
    fill(sy, sy + N, 0);
    sort(p, p + n);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (!i || p[i].F != p[i - 1].F)
            mx[p[i].F] = cnt++;
    cnt = 0;
    sort(p, p + n, cmp2);
    for (int i = 0; i < n; ++i)
        if (!i || p[i].S != p[i - 1].S)
            my[p[i].S] = cnt++;
    for (int i = 0; i < n; ++i)
        ++sy[my[p[i].S]];
    for (int i = 0; i < my.size(); ++i)
        if (i)
            sy[i] += sy[i - 1];
    for (int i = 0; i < n; ++i)
    {
        atx[mx[p[i].F]].push_back(my[p[i].S]);
        ++sx[mx[p[i].F]];
    }
    for (int i = 0; i < mx.size(); ++i)
    {
        sort(atx[i].begin(), atx[i].end());
        if (i)
            sx[i] += sx[i - 1];
    }
    build(0, 0, mx.size() - 1);
}

int a[9];
bool ok = false;

void solve()
{
    if (ok)
        return;
    int s1 = a[0] + a[3] + a[6];
    int s2 = a[1] + a[4] + a[7];
    int s3 = a[2] + a[5] + a[8];
    int i1 = lower_bound(sx, sx + mx.size(), s1) - sx;
    if (sx[i1] != s1)
        return;
    int i2 = lower_bound(sx, sx + mx.size(), s1 + s2) - sx;
    if (sx[i2] != s1 + s2)
        return;
    s1 = a[0] + a[1] + a[2];
    s2 = a[3] + a[4] + a[5];
    s3 = a[6] + a[7] + a[8];
    int j1 = lower_bound(sy, sy + my.size(), s1) - sy;
    if (sy[j1] != s1)
        return;
    int j2 = lower_bound(sy, sy + my.size(), s1 + s2) - sy;
    if (sy[j2] != s1 + s2)
        return;
    int t1 = getCnt(0, 0, i1, 0, j1);
    int t2 = getCnt(0, i1 + 1, i2, 0, j1);
    int t4 = getCnt(0, 0, i1, j1 + 1, j2);
    int t5 = getCnt(0, i1 + 1, i2, j1 + 1, j2);
    if (t1 != a[0] || t2 != a[1] || t4 != a[3] || t5 != a[4])
        return;

    ok = true;

    //cerr << i1 << " " << i2 << " " << j1 << " " << j2 << endl;

    for (int i = 0; i < n; ++i)
        if (mx[p[i].F] == i1)
        {
            printf("%lf ", p[i].F + double(0.5));
            break;
        }
    for (int i = 0; i < n; ++i)
        if (mx[p[i].F] == i2)
        {
            printf("%lf\n", p[i].F + double(0.5));
            break;
        }
    for (int i = 0; i < n; ++i)
        if (my[p[i].S] == j1)
        {
            printf("%lf ", p[i].S + double(0.5));
            break;
        }
    for (int i = 0; i < n; ++i)
        if (my[p[i].S] == j2)
        {
            printf("%lf\n", p[i].S + double(0.5));
            break;
        }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", & n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", & p[i].F, & p[i].S);
    for (int i = 0; i < 9; ++i)
        scanf("%d", & a[i]);

    int perm[9];
    for (int i = 0; i < 9; ++i)
        perm[i] = i;

    init();

    for (;;)
    {
        int temp[9];
        int mem[9];
        copy(a, a + 9, mem);
        for (int i = 0; i < 9; ++i)
            temp[i] = a[perm[i]];
        copy(temp, temp + 9, a);
        solve();
        if (!next_permutation(perm, perm + 9))
            break;
        copy(mem, mem + 9, a);
    }

    if (!ok)
        puts("-1");

    return 0;
}