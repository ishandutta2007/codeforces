#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxm = 2097152;

struct node {
    ll lefval;
    int lefdec, lefbest;
    ll rigval;
    int rigdec, rigbest;
    int cnt;
    int mx;
};

int n;
int a[Maxn];
node st[Maxm];
ll flag[Maxm];
int m;

void downOn(int v, ll f)
{
    st[v].lefval += f;
    st[v].rigval += f;
    flag[v] += f;
}

void Down(int v)
{
    if (flag[v]) {
        downOn(2 * v, flag[v]);
        downOn(2 * v + 1, flag[v]);
        flag[v] = 0;
    }
}

void Union(int v)
{
    int lc = 2 * v, rc = 2 * v + 1;

    st[v].lefval = st[lc].lefval;
    st[v].lefdec = st[lc].lefdec == st[lc].cnt && st[lc].rigval > st[rc].lefval?
                   st[lc].lefdec + st[rc].lefdec: st[lc].lefdec;
    st[v].lefbest = st[lc].lefbest;
    if (st[lc].lefbest == st[lc].cnt && st[lc].rigval > st[rc].lefval)
        st[v].lefbest = max(st[v].lefbest, st[lc].cnt + st[rc].lefdec);
    if (st[lc].rigdec == st[lc].cnt && st[lc].rigval < st[rc].lefval)
        st[v].lefbest = max(st[v].lefbest, st[lc].cnt + st[rc].lefbest);

    st[v].rigval = st[rc].rigval;
    st[v].rigdec = st[rc].rigdec == st[rc].cnt && st[rc].lefval > st[lc].rigval?
                   st[rc].rigdec + st[lc].rigdec: st[rc].rigdec;
    st[v].rigbest = st[rc].rigbest;
    if (st[rc].rigbest == st[rc].cnt && st[rc].lefval > st[lc].rigval)
        st[v].rigbest = max(st[v].rigbest, st[rc].cnt + st[lc].rigdec);
    if (st[rc].lefdec == st[rc].cnt && st[rc].lefval < st[lc].rigval)
        st[v].rigbest = max(st[v].rigbest, st[rc].cnt + st[lc].rigbest);

    st[v].cnt = st[lc].cnt + st[rc].cnt;
    st[v].mx = max(st[lc].mx, st[rc].mx);
    if (st[lc].rigval > st[rc].lefval)
        st[v].mx = max(st[v].mx, st[lc].rigbest + st[rc].lefdec);
    else if (st[lc].rigval < st[rc].lefval)
        st[v].mx = max(st[v].mx, st[lc].rigdec + st[rc].lefbest);
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].lefval = st[v].rigval = a[l];
        st[v].lefdec = st[v].lefbest = st[v].rigdec = st[v].rigbest = st[v].mx = st[v].cnt = 1;
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int a, int b, ll c)
{
    if (l == a && r == b) downOn(v, c);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), c);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, c);
        Union(v);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Create(1, 1, n);
    scanf("%d", &m);
    while (m--) {
        int a, b, d; scanf("%d %d %d", &a, &b, &d);
        Update(1, 1, n, a, b, d);
        printf("%d\n", st[1].mx);
    }
    return 0;
}