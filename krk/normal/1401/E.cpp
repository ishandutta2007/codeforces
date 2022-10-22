#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int lim = 1000000;
const int Maxn = 1000005;
const int Maxm = 4194304;

vector <int> st[2][Maxm];
vector <int> my[2][Maxn];
int n, m;
ll res = 1;

void Create(int t, int v, int l, int r)
{
    if (l == r) st[t][v] = my[t][l];
    else {
        int m = l + r >> 1;
        int lc = 2 * v, rc = 2 * v + 1;
        Create(t, lc, l, m);
        Create(t, rc, m + 1, r);
        merge(st[t][lc].begin(), st[t][lc].end(), st[t][rc].begin(), st[t][rc].end(), inserter(st[t][v], st[t][v].begin()));
    }
}

int Get(int t, int v, int l, int r, int a, int b, int val)
{
    if (l == a && r == b)
        if (t == 0) return st[t][v].end() - lower_bound(st[t][v].begin(), st[t][v].end(), val);
        else return upper_bound(st[t][v].begin(), st[t][v].end(), val) - st[t][v].begin();
    else {
        int m = l + r >> 1;
        int res = 0;
        if (a <= m) res += Get(t, 2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) res += Get(t, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        return res;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int y, lx, rx; scanf("%d %d %d", &y, &lx, &rx);
        if (lx == 0) {
            if (rx == lim) res++;
            my[0][y].push_back(rx);
        } else my[1][y].push_back(lx);
    }
    Create(0, 1, 0, lim);
    Create(1, 1, 0, lim);
    for (int i = 0; i < m; i++) {
        int x, ly, ry; scanf("%d %d %d", &x, &ly, &ry);
        if (ly == 0 && ry == lim) res++;
        res += Get(0, 1, 0, lim, ly, ry, x) + Get(1, 1, 0, lim, ly, ry, x);
    }
    cout << res << endl;
    return 0;
}