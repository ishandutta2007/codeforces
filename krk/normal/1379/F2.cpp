#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Inf = 1000000000;

struct node {
    bool found;
    int mn1, mx0;
    node(): found(false), mn1(Inf), mx0(-Inf) {}
};

int n, m, q;
set <int> O[Maxn], Z[Maxn];
node st[Maxm];

node Union(const node &a, const node &b)
{
    node res;
    res.found = a.found || b.found || a.mn1 <= b.mx0;
    res.mn1 = min(a.mn1, b.mn1);
    res.mx0 = max(a.mx0, b.mx0);
    return res;
}

void Update(int v, int l, int r, int x)
{
    if (l == r) {
        st[v].mn1 = O[l].empty()? Inf: *O[l].begin();
        st[v].mx0 = Z[l].empty()? -Inf: *Z[l].rbegin();
        st[v].found = st[v].mn1 <= st[v].mx0;
    } else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x);
        else Update(2 * v + 1, m + 1, r, x);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        int r = (x - 1) / 2 + 1;
        int c = (y - 1) / 2 + 1;
        int col = (x - 1) % 2;
        if (col == 0)
            if (O[c].find(r) != O[c].end()) O[c].erase(r);
            else O[c].insert(r);
        else if (Z[c].find(r) != Z[c].end()) Z[c].erase(r);
             else Z[c].insert(r);
        Update(1, 1, m, c);
        printf("%s\n", st[1].found? "NO": "YES");
    }
    return 0;
}