#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;

struct node {
    int mn, mx;
    int lef, rig;
    int best;
};

int n, q;
char str[Maxn];
int a[Maxn];
node st[Maxm];
int fl[Maxm];

void downOn(int v, int f)
{
    st[v].mn += f; st[v].mx += f;
    st[v].lef -= f; st[v].rig -= f;
    fl[v] += f;
}

void Down(int v)
{
    if (fl[v]) {
        downOn(2 * v, fl[v]);
        downOn(2 * v + 1, fl[v]);
        fl[v] = 0;
    }
}

void Union(int v)
{
    int lc = 2 * v, rc = 2 * v + 1;
    st[v].mn = min(st[lc].mn, st[rc].mn);
    st[v].mx = max(st[lc].mx, st[rc].mx);
    st[v].lef = max(max(st[lc].lef, st[rc].lef), st[rc].mx - 2 * st[lc].mn);
    st[v].rig = max(max(st[lc].rig, st[rc].rig), st[lc].mx - 2 * st[rc].mn);
    st[v].best = max(max(st[lc].best, st[rc].best), max(st[lc].rig + st[rc].mx, st[lc].mx + st[rc].lef));
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].mn = st[v].mx = a[l];
        st[v].lef = st[v].rig = -a[l];
        st[v].best = 0;
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int a, int b, int delt)
{
    if (l == a && r == b) downOn(v, delt);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        Union(v);
    }
}

int main()
{
    scanf("%d %d", &n, &q); n--;
    scanf("%s", str + 1);
    int cur = 0;
    for (int i = 1; i <= 2 * n; i++) {
        cur += str[i] == '('? 1: -1;
        a[i] = cur;
    }
    Create(1, 0, 2 * n);
    printf("%d\n", st[1].best);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        if (l > r) swap(l, r);
        if (str[l] != str[r]) {
            swap(str[l], str[r]);
            Update(1, 0, 2 * n, l, r - 1, str[l] == '('? 2: -2);
        }
        printf("%d\n", st[1].best);
    }
    return 0;
}