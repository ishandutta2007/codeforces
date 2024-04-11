#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 524288;

struct node {
    vector <int> mx;
    int n;
    node(int gn = 1) {
        n = gn;
        int m = 1;
        while (m <= 4 * gn) m *= 2;
        mx.resize(m);
    }
    void Create(int v, int l, int r, const vector <int> &vals)
    {
        if (l == r) mx[v] = vals[l];
        else {
            int m = l + r >> 1;
            Create(2 * v, l, m, vals);
            Create(2 * v + 1, m + 1, r, vals);
            mx[v] = max(mx[2 * v], mx[2 * v + 1]);
        }
    }
    void Create(const vector <int> &vals) { Create(1, 0, n - 1, vals); }
    int Get(int v, int l, int r, int a, int b)
    {
        if (l == a && r == b) return mx[v];
        else {
            int m = l + r >> 1;
            if (b <= m) return Get(2 * v, l, m, a, b);
            if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
            return max(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
        }
    }
    int Get(int l, int r) { return Get(1, 0, n - 1, l, r); }
};

int n, k;
int r[Maxn];
int a[Maxn];
vector <int> unr, una;
vector <int> my[Maxn];
vector <ii> my2[Maxn];
int BIT[Maxn];
vector <int> st[Maxm], mx[Maxm];
node tr[Maxm];

void Insert(int x)
{
    x++;
    for (int i = x; i <= una.size(); i += i & -i)
        BIT[i]++;
}

int Get(int x)
{
    x++;
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

void Insert(int v, int l, int r, int x, int y, int val)
{
    if (st[v].empty() || st[v].back() != y) {
        st[v].push_back(y);
        mx[v].push_back(val);
    } else mx[v].back() = max(mx[v].back(), val);
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) Insert(2 * v, l, m, x, y, val);
        else Insert(2 * v + 1, m + 1, r, x, y, val);
    }
}

void Create(int v, int l, int r)
{
    tr[v] = node(st[v].size());
    tr[v].Create(mx[v]);
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
    }
}

int getMax(int v, int l, int r, int a, int b, int y1, int y2)
{
    if (l == a && r == b) {
        int l = lower_bound(st[v].begin(), st[v].end(), y1) - st[v].begin();
        int r = upper_bound(st[v].begin(), st[v].end(), y2) - st[v].begin() - 1;
        return l <= r? tr[v].Get(l, r): 0;
    } else {
        int m = l + r >> 1;
        if (b <= m) return getMax(2 * v, l, m, a, b, y1, y2);
        if (m + 1 <= a) return getMax(2 * v + 1, m + 1, r, a, b, y1, y2);
        return max(getMax(2 * v, l, m, a, m, y1, y2), getMax(2 * v + 1, m + 1, r, m + 1, b, y1, y2));
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &r[i]);
        unr.push_back(r[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        una.push_back(a[i]);
    }
    sort(unr.begin(), unr.end());
    unr.erase(unique(unr.begin(), unr.end()), unr.end());
    sort(una.begin(), una.end());
    una.erase(unique(una.begin(), una.end()), una.end());
    for (int i = 1; i <= n; i++) {
        int indr = lower_bound(unr.begin(), unr.end(), r[i]) - unr.begin();
        my[indr].push_back(a[i]);
    }
    for (int i = 0; i < unr.size(); i++) {
        sort(my[i].begin(), my[i].end());
        for (int j = 0; j < my[i].size(); j++) {
            int ind = lower_bound(una.begin(), una.end(), my[i][j]) - una.begin();
            Insert(ind);
        }
        for (int j = 0; j < my[i].size(); j++) {
            int l = lower_bound(una.begin(), una.end(), my[i][j] - k) - una.begin();
            int r = upper_bound(una.begin(), una.end(), my[i][j] + k) - una.begin() - 1;
            int ind = lower_bound(una.begin(), una.end(), my[i][j]) - una.begin();
            int val = Get(r) - Get(l - 1);
            my2[ind].push_back(ii(i, val));
        }
    }
    for (int i = 0; i < una.size(); i++)
        for (int j = 0; j < my2[i].size(); j++)
            Insert(1, 0, int(unr.size()) - 1, my2[i][j].first, una[i], my2[i][j].second);
    Create(1, 0, int(unr.size()) - 1);
    int q; scanf("%d", &q);
    while (q--) {
        int u, v; scanf("%d %d", &u, &v);
        int ind = lower_bound(unr.begin(), unr.end(), max(r[u], r[v])) - unr.begin();
        if (a[u] > a[v]) swap(u, v);
        int res = getMax(1, 0, int(unr.size()) - 1, ind, int(unr.size()) - 1, a[v] - k, a[u] + k);
        if (res == 0) res = -1;
        printf("%d\n", res);
    }
    return 0;
}