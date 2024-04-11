#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
const int Maxm = 2097152;

struct pos {
    int ones, zers;
    bool flag;
};

int n, q;
pos st[Maxm];
int a[Maxn];

void Create(int v, int l, int r)
{
    st[v].ones = 0;
    st[v].zers = r - l + 1;
    st[v].flag = false;
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
    }
}

void downOn(int v)
{
    swap(st[v].ones, st[v].zers);
    st[v].flag ^= true;
}

void Down(int v)
{
    if (st[v].flag) {
        downOn(2 * v);
        downOn(2 * v + 1);
        st[v].flag = false;
    }
}

void Union(int v)
{
    int lc = 2 * v, rc = 2 * v + 1;
    st[v].ones = st[lc].ones + st[rc].ones;
    st[v].zers = st[lc].zers + st[rc].zers;
}

void Flip(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) downOn(v);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Flip(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) Flip(2 * v + 1, m + 1, r, max(m + 1, a), b);
        Union(v);
    }
}

int getSmallest(int v, int l, int r, int x, bool one)
{
    if (r < x || one && st[v].ones == 0 || !one && st[v].zers == 0) return Maxn;
    if (l == r) return l;
    else {
        Down(v);
        int m = l + r >> 1;
        int res = getSmallest(2 * v, l, m, x, one);
        if (res == Maxn)
            res = getSmallest(2 * v + 1, m + 1, r, x, one);
        return res;
    }
}

int getAnswer(int v, int l, int r)
{
    if (st[v].ones == 0) return -1;
    if (l == r) return l;
    else {
        Down(v);
        int m = l + r >> 1;
        int res = getAnswer(2 * v + 1, m + 1, r);
        if (res == -1)
            res = getAnswer(2 * v, l, m);
        return res;
    }
}

void Add(int ind)
{
    int to = getSmallest(1, 0, Maxn - 1, ind, false);
    Flip(1, 0, Maxn - 1, ind, to);
}

void Sub(int ind)
{
    int to = getSmallest(1, 0, Maxn - 1, ind, true);
    Flip(1, 0, Maxn - 1, ind, to);
}

int main()
{
    scanf("%d %d", &n, &q);
    Create(1, 0, Maxn - 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        Add(a[i]);
    }
    while (q--) {
        int ind, val; scanf("%d %d", &ind, &val);
        if (a[ind] != val) {
            Sub(a[ind]);
            a[ind] = val;
            Add(a[ind]);
        }
        printf("%d\n", getAnswer(1, 0, Maxn - 1));
    }
    return 0;
}