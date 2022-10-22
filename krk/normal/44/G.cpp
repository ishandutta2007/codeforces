#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 524288;
const int lim = 1000000007;

int n;
int X1[Maxn], X2[Maxn], Y1[Maxn], Y2[Maxn], Z[Maxn];
bool tk[Maxn];
ii srt[Maxn];
int mx;

struct segtree {
    vector <vector <int> > st;
    int n;
    segtree(int gn = 0) {
        if (gn == 0) return;
        n = gn;
        int m = 1;
        while (m <= 2 * n) m *= 2;
        st.resize(m);
    }
    void Add(int v, int l, int r, int a, int b, int ind)
    {
        if (l == a && r == b) st[v].push_back(ind);
        else {
            int m = l + r >> 1;
            if (a <= m) Add(2 * v, l, m, a, min(m, b), ind);
            if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, ind);
        }
    }
    void Add(int a, int b, int ind) { Add(1, 0, n - 1, a, b, ind); }
    int Get(int v, int l, int r, int x)
    {
        while (!st[v].empty() && tk[st[v].back()]) st[v].pop_back();
        int res = st[v].empty()? 0: st[v].back();
        if (l < r) {
            int m = l + r >> 1;
            int got = x <= m? Get(2 * v, l, m, x): Get(2 * v + 1, m + 1, r, x);
            if (Z[got] < Z[res]) res = got;
        }
        return res;
    }
    int Get(int x) { return Get(1, 0, n - 1, x); }
};

vector <int> un[Maxm];
segtree st[Maxm];
vector <int> gun;

void initAdd(int v, int l, int r, int a, int b, int y1, int y2)
{
    if (l == a && r == b) {
        un[v].push_back(y1);
        un[v].push_back(y2);
    } else {
        int m = l + r >> 1;
        if (a <= m) initAdd(2 * v, l, m, a, min(m, b), y1, y2);
        if (m + 1 <= b) initAdd(2 * v + 1, m + 1, r, max(m + 1, a), b, y1, y2);
    }
}

void Add(int v, int l, int r, int a, int b, int y1, int y2, int ind)
{
    if (l == a && r == b) {
        int lef = lower_bound(un[v].begin(), un[v].end(), y1) - un[v].begin();
        int rig = lower_bound(un[v].begin(), un[v].end(), y2) - un[v].begin();
        st[v].Add(lef, rig - 1, ind);
    } else {
        int m = l + r >> 1;
        if (a <= m) Add(2 * v, l, m, a, min(m, b), y1, y2, ind);
        if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, y1, y2, ind);
    }
}

void Fix(int v, int l, int r)
{
    sort(un[v].begin(), un[v].end());
    un[v].erase(unique(un[v].begin(), un[v].end()), un[v].end());
    st[v] = segtree(un[v].size());
    if (l < r) {
        int m = l + r >> 1;
        Fix(2 * v, l, m);
        Fix(2 * v + 1, m + 1, r);
    }
}

int Get(int v, int l, int r, int x, int y)
{
    int res;
    if (un[v].empty()) res = 0;
    else {
        int ind = upper_bound(un[v].begin(), un[v].end(), y) - un[v].begin() - 1;
        if (ind < 0 || ind >= un[v].size()) res = 0;
        else res = st[v].Get(ind);
    }
    if (l < r) {
        int m = l + r >> 1;
        int got = x <= m? Get(2 * v, l, m, x, y): Get(2 * v + 1, m + 1, r, x, y);
        if (Z[got] < Z[res]) res = got;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d %d", &X1[i], &X2[i], &Y1[i], &Y2[i], &Z[i]);
        gun.push_back(X1[i]);
        gun.push_back(X2[i] + 1);
        srt[i - 1] = ii(Z[i], i);
    }
    sort(gun.begin(), gun.end());
    gun.erase(unique(gun.begin(), gun.end()), gun.end());
    Z[0] = lim;
    sort(srt, srt + n);
    for (int i = n - 1; i >= 0; i--) {
        int ind = srt[i].second;
        int lef = lower_bound(gun.begin(), gun.end(), X1[ind]) - gun.begin();
        int rig = lower_bound(gun.begin(), gun.end(), X2[ind] + 1) - gun.begin();
        initAdd(1, 0, int(gun.size()) - 1, lef, rig - 1, Y1[ind], Y2[ind] + 1);
    }
    Fix(1, 0, int(gun.size()) - 1);
    for (int i = n - 1; i >= 0; i--) {
        int ind = srt[i].second;
        int lef = lower_bound(gun.begin(), gun.end(), X1[ind]) - gun.begin();
        int rig = lower_bound(gun.begin(), gun.end(), X2[ind] + 1) - gun.begin();
        Add(1, 0, int(gun.size()) - 1, lef, rig - 1, Y1[ind], Y2[ind] + 1, ind);
    }
    int m; scanf("%d", &m);
    while (m--) {
        int x, y; scanf("%d %d", &x, &y);
        int ind = upper_bound(gun.begin(), gun.end(), x) - gun.begin() - 1;
        if (ind < 0 || ind >= gun.size()) printf("0\n");
        else {
            int res = Get(1, 0, int(gun.size()) - 1, ind, y);
            if (res) tk[res] = true;
            printf("%d\n", res);
        }
    }
    return 0;
}