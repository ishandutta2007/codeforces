#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxd = 4;
const int Maxn = 400004;
const int Maxm = 2097152;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n;
int X[Maxn], Y[Maxn];
set <ii> S;
vector <int> my[Maxn];
vector <int> st[Maxm];

void Create(int v, int l, int r)
{
    if (l == r) {
        sort(my[l].begin(), my[l].end());
        my[l].erase(unique(my[l].begin(), my[l].end()), my[l].end());
        st[v] = my[l];
    } else {
        int m = l + r >> 1;
        int lc = 2 * v, rc = 2 * v + 1;
        Create(lc, l, m);
        Create(rc, m + 1, r);
        set_union(st[lc].begin(), st[lc].end(), st[rc].begin(), st[rc].end(), inserter(st[v], st[v].begin()));
    }
}

bool Has(int v, int l, int r, int a, int b, int c, int d)
{
    if (l == a && r == b) {
        int ind = lower_bound(st[v].begin(), st[v].end(), c) - st[v].begin();
        return ind < st[v].size() && st[v][ind] <= d;
    } else {
        int m = l + r >> 1;
        bool res = false;
        if (a <= m) res = Has(2 * v, l, m, a, min(m, b), c, d);
        if (res) return true;
        if (m + 1 <= b) res = Has(2 * v + 1, m + 1, r, max(m + 1, a), b, c, d);
        return res;
    }
}

ii Get(int v, int l, int r, int a, int b, int c, int d)
{
    int ind;
    if (l <= a && b <= r) {
        ind = lower_bound(st[v].begin(), st[v].end(), c) - st[v].begin();
        if (ind >= st[v].size() || st[v][ind] > d) return ii(-1, -1);
    }
    if (l == r) return ii(l, st[v][ind]);
    else {
        int m = l + r >> 1;
        ii res = ii(-1, -1);
        if (a <= m) res = Get(2 * v, l, m, a, min(m, b), c, d);
        if (res.first != -1) return res;
        if (m + 1 <= b) res = Get(2 * v  +1, m + 1, r, max(m + 1, a), b, c, d);
        return res;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        S.insert(ii(X[i], Y[i]));
    }
    for (int z = 0; z < n; z++) {
        ii p = ii(X[z], Y[z]);
        for (int i = 0; i < Maxd; i++) {
            ii u = ii(p.first + dy[i], p.second + dx[i]);
            if (S.find(u) == S.end())
                my[u.first + u.second].push_back(u.first - u.second);
        }
    }
    Create(1, 0, Maxn - 1);
    for (int i = 0; i < n; i++) {
        int A = X[i] + Y[i], B = X[i] - Y[i];
        int lef = 1, rig = min(A, Maxn - 1 - A);
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (!Has(1, 0, Maxn - 1, A - mid, A + mid, B - mid, B + mid)) lef = mid + 1;
            else rig = mid - 1;
        }
        auto got = Get(1, 0, Maxn - 1, A - lef, A + lef, B - lef, B + lef);
        int resX = (got.first + got.second) / 2, resY = (got.first - got.second) / 2;
        printf("%d %d\n", resX, resY);
    }
    return 0;
}