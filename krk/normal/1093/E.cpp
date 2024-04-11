#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Maxd = 5;

int n, m;
int a[Maxn], b[Maxn];
int c[Maxn];
int mya[Maxn], myb[Maxn];
vector <int> un[Maxm], BIT[Maxm];
vector <int> my[Maxn];
int quer[Maxn][Maxd];

void Insert(vector <int> &BIT, int ind, int val)
{
    ind++;
    for (int i = ind; i < BIT.size(); i += i & -i)
        BIT[i] += val;
}

int Get(const vector <int> &BIT, int ind)
{
    ind++;
    int res = 0;
    for (int i = ind; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        sort(my[l].begin(), my[l].end());
        my[l].erase(unique(my[l].begin(), my[l].end()), my[l].end());
        un[v] = my[l];
    } else {
        int m = l + r >> 1;
        int lc = 2 * v, rc = 2 * v + 1;
        Create(lc, l, m);
        Create(rc, m + 1, r);
        set_union(un[lc].begin(), un[lc].end(), un[rc].begin(), un[rc].end(),
                  inserter(un[v], un[v].begin()));
    }
    BIT[v].resize(un[v].size() + 1, 0);
}

void Update(int v, int l, int r, int a, int b, int delt)
{
    int ind = lower_bound(un[v].begin(), un[v].end(), b) - un[v].begin();
    Insert(BIT[v], ind, delt);
    if (l < r) {
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, b, delt);
        else Update(2 * v + 1, m + 1, r, a, b, delt);
    }
}

int Get(int v, int l, int r, int l1, int r1, int l2, int r2)
{
    if (l == l1 && r == r1) {
        int ind1 = lower_bound(un[v].begin(), un[v].end(), l2) - un[v].begin() - 1;
        int ind2 = upper_bound(un[v].begin(), un[v].end(), r2) - un[v].begin() - 1;
        if (ind1 < ind2) return Get(BIT[v], ind2) - Get(BIT[v], ind1);
        else return 0;
    } else {
        int m = l + r >> 1;
        int res = 0;
        if (l1 <= m) res += Get(2 * v, l, m, l1, min(m, r1), l2, r2);
        if (m + 1 <= r1) res += Get(2 * v + 1, m + 1, r, max(m + 1, l1), r1, l2, r2);
        return res;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mya[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        myb[b[i]] = i;
        c[i] = b[i];
    }
    for (int i = 1; i <= n; i++)
        my[mya[i]].push_back(myb[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d", &quer[i][0]);
        if (quer[i][0] == 1)
            for (int j = 1; j < Maxd; j++)
                scanf("%d", &quer[i][j]);
        else {
            int u, v; scanf("%d %d", &u, &v);
            quer[i][1] = u; quer[i][2] = v;
            swap(c[u], c[v]);
            myb[c[u]] = u;
            my[mya[c[u]]].push_back(myb[c[u]]);
            myb[c[v]] = v;
            my[mya[c[v]]].push_back(myb[c[v]]);
        }
    }
    Create(1, 1, n);
    for (int i = 1; i <= n; i++) {
        c[i] = b[i];
        myb[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        Update(1, 1, n, mya[i], myb[i], 1);
    for (int i = 0; i < m; i++)
        if (quer[i][0] == 1)
            printf("%d\n", Get(1, 1, n, quer[i][1], quer[i][2], quer[i][3], quer[i][4]));
        else {
            int u = quer[i][1], v = quer[i][2];
            Update(1, 1, n, mya[c[u]], myb[c[u]], -1);
            Update(1, 1, n, mya[c[v]], myb[c[v]], -1);
            swap(c[u], c[v]);
            myb[c[u]] = u; myb[c[v]] = v;
            Update(1, 1, n, mya[c[u]], myb[c[u]], 1);
            Update(1, 1, n, mya[c[v]], myb[c[v]], 1);
        }
    return 0;
}