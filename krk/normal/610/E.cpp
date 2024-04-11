#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Maxk = 10;

struct node {
    int lef, rig;
    int has[Maxk][Maxk];
    int flag;
};

int n, m, k;
char str[Maxn + 1];
node st[Maxm];
char tmp[Maxk + 5];
int wh[Maxk];

void downOn(int v, int sz, int c)
{
    st[v].lef = st[v].rig = st[v].flag = c;
    fill((int*)st[v].has, (int*)st[v].has + Maxk * Maxk, 0);
    st[v].has[c][c] = sz - 1;
}

void Down(int v, int l, int m, int r)
{
    if (st[v].flag != -1) {
        downOn(2 * v, m - l + 1, st[v].flag);
        downOn(2 * v + 1, r - m, st[v].flag);
        st[v].flag = -1;
    }
}

void Union(int v)
{
    int lc = 2 * v, rc = 2 * v + 1;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            st[v].has[i][j] = st[lc].has[i][j] + st[rc].has[i][j];
    st[v].lef = st[lc].lef;
    st[v].rig = st[rc].rig;
    st[v].has[st[lc].rig][st[rc].lef]++;
}

void Create(int v, int l, int r)
{
    st[v].lef = str[l] - 'a';
    st[v].rig = str[r] - 'a';
    st[v].flag = -1;
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int a, int b, int c)
{
    if (l == a && r == b) downOn(v, r - l + 1, c);
    else {
        int m = l + r >> 1;
        Down(v, l, m, r);
        if (a <= m) Update(2 * v, l, m, a, min(m, b), c);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, c);
        Union(v);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    scanf("%s", str + 1);
    Create(1, 1, n);
    while (m--) {
        int typ; scanf("%d", &typ);
        if (typ == 1) {
            int l, r; char ch; scanf("%d %d %c", &l, &r, &ch);
            Update(1, 1, n, l, r, ch - 'a');
        } else {
            scanf("%s", tmp);
            for (int i = 0; i < k; i++)
                wh[tmp[i] - 'a'] = i;
            ll res = 1;
            for (int i = 0; i < k; i++)
                for (int j = 0; j < k; j++)
                    res += ll(st[1].has[i][j]) * (wh[i] >= wh[j]);
            printf("%I64d\n", res);
        }
    }
    return 0;
}