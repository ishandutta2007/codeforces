#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Maxl = 26;
const int Inf = 1000000000;
const ll bInf = 1000000000000000000ll;

struct node {
    int mn[Maxl];
    int siz;
    void Clear() {
        fill(mn, mn + Maxl, Inf);
        siz = 0;
    }
    node() {
        Clear();
    }
};

int q;
int n;
char S[Maxn];
char T[Maxn];
node st[Maxm];

void Union(int v)
{
    int lc = 2 * v, rc = 2 * v + 1;
    for (int i = 0; i < Maxl; i++)
        st[v].mn[i] = min(st[lc].mn[i], st[rc].mn[i] + st[lc].siz);
    st[v].siz = st[lc].siz + st[rc].siz;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].Clear();
        st[v].mn[S[l] - 'a'] = 0;
        st[v].siz = 1;
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Erase(int v, int l, int r, int x)
{
    if (l == r) st[v].Clear();
    else {
        int m = l + r >> 1;
        if (x < st[2 * v].siz) Erase(2 * v, l, m, x);
        else Erase(2 * v + 1, m + 1, r, x - st[2 * v].siz);
        Union(v);
    }
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        scanf("%s", S);
        scanf("%s", T);
        Create(1, 0, n - 1);
        ll res = bInf;
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            int ind = T[i] - 'a';
            for (int j = 0; j < ind; j++) if (st[1].mn[j] < Inf)
                res = min(res, cur + st[1].mn[j]);
            if (st[1].mn[ind] < Inf) {
                cur += st[1].mn[ind];
                Erase(1, 0, n - 1, st[1].mn[ind]);
            } else break;
        }
        printf("%I64d\n", res >= bInf? -1ll: res);
    }
    return 0;
}