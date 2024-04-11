#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

struct segtree {
    vector <vector <int> > st, BIT;
    int n;
    segtree(): n(0) {}
    void Add(vector <int> &BIT, int x, int delt)
    {
        for (int i = x + 1; i > 0; i -= i & -i)
            BIT[i] += delt;
    }
    int Get(const vector <int> &BIT, int x)
    {
        int res = 0;
        for (int i = x + 1; i < BIT.size(); i += i & -i)
            res += BIT[i];
        return res;
    }
    void addZeroes(int v, int l, int r) {
        st[v].push_back(0);
        if (l < r) {
            int m = l + r >> 1;
            addZeroes(2 * v, l, m);
            addZeroes(2 * v + 1, m + 1, r);
        }
    }
    void createBits(int v, int l, int r) {
        BIT[v].resize(st[v].size() + 1, 0);
        Add(BIT[v], 0, r - l + 1);
        if (l < r) {
            int m = l + r >> 1;
            createBits(2 * v, l, m);
            createBits(2 * v + 1, m + 1, r);
        }
    }
    void addSt(int v, int l, int r, int x, int val)
    {
        st[v].push_back(val);
        if (l < r) {
            int m = l + r >> 1;
            if (x <= m) addSt(2 * v, l, m, x, val);
            else addSt(2 * v + 1, m + 1, r, x, val);
        }
    }
    void Update(int v, int l, int r, int x, int old, int nw)
    {
        int ind = lower_bound(st[v].begin(), st[v].end(), old) - st[v].begin();
        Add(BIT[v], ind, -1);
        ind = lower_bound(st[v].begin(), st[v].end(), nw) - st[v].begin();
        Add(BIT[v], ind, 1);
        if (l < r) {
            int m = l + r >> 1;
            if (x <= m) Update(2 * v, l, m, x, old, nw);
            else Update(2 * v + 1, m + 1, r, x, old, nw);
        }
    }
    int Get(int v, int l, int r, int a, int b, int y)
    {
        if (l == a && r == b) {
            int ind = upper_bound(st[v].begin(), st[v].end(), y) - st[v].begin();
            return Get(BIT[v], ind);
        } else {
            int res = 0;
            int m = l + r >> 1;
            if (a <= m) res += Get(2 * v, l, m, a, min(m, b), y);
            if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b, y);
            return res;
        }
    }
    int getInd(int v, int l, int r, int a, int b, int &k, int y)
    {
        if (l == a && r == b) {
            int ind = upper_bound(st[v].begin(), st[v].end(), y) - st[v].begin();
            int has = r - l + 1 - Get(BIT[v], ind);
            if (has < k) { k -= has; return -1; }
        }
        if (l == r) return l;
        else {
            int m = l + r >> 1;
            int got = -1;
            if (a <= m) got = getInd(2 * v, l, m, a, min(m, b), k, y);
            if (got != -1) return got;
            if (m + 1 <= b) got = getInd(2 * v + 1, m + 1, r, max(m + 1, a), b, k, y);
            return got;
        }
    }
    void Create(int gn) {
        n = gn;
        int m = 1;
        while (m <= 4 * n) m *= 2;
        st.resize(m); BIT.resize(m);
        addZeroes(1, 0, n - 1);
    }
    void createAdd(int id, int val) {
        addSt(1, 0, n - 1, id, val);
    }
    void postCreate() {
        createBits(1, 0, n - 1);
    }
    void Update(int id, int oldval, int newval) {
        Update(1, 0, n - 1, id, oldval, newval);
    }
    int Get(int a, int b, int y) {
        return b - a + 1 - Get(1, 0, n - 1, a, b, y);
    }
    int getInd(int a, int b, int k, int y) {
        return getInd(1, 0, n - 1, a, b, k, y);
    }
};

int n;
int P[Maxn];
vector <int> neigh[Maxn];
int root;
int L[Maxn], cnt[Maxn];
int head[Maxn], id[Maxn];
vector <int> inhead[Maxn];
segtree tr[Maxn];
int m;
int typ[Maxn], qa[Maxn], qb[Maxn], qk[Maxn], qy[Maxn];
int cur[Maxn];

void Traverse(int v)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        L[u] = L[v] + 1;
        Traverse(u);
        cnt[v] += cnt[u];
    }
}

void BuildHLD(int v)
{
    inhead[head[v]].push_back(v);
    bool cont = false;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (cnt[u] > cnt[v] / 2) {
            cont = true;
            head[u] = head[v]; id[u] = id[v] + 1;
        } else {
            head[u] = u; id[u] = 0;
        }
        BuildHLD(u);
    }
    if (!cont) tr[head[v]].Create(id[v] + 1);
}

int Get(int a, int b, int k, int y)
{
    if (cur[a] <= y) k++;
    int forb = b;
    vector <ii> A, B;
    while (head[a] != head[b])
        if (L[head[a]] >= L[head[b]]) {
            A.push_back(ii(head[a], a));
            a = P[head[a]];
        } else {
            B.push_back(ii(head[b], b));
            b = P[head[b]];
        }
    if (L[a] >= L[b]) A.push_back(ii(b, a));
    else B.push_back(ii(a, b));
    for (int i = 0; i < A.size(); i++) {
        int lef = id[A[i].first], rig = id[A[i].second];
        int v = head[A[i].first];
        int got = tr[v].Get(lef, rig, y);
        if (got >= k) {
            int res = inhead[v][tr[v].getInd(lef, rig, got + 1 - k, y)];
            return res == forb? -1: res;
        } else k -= got;
    }
    for (int i = int(B.size()) - 1; i >= 0; i--) {
        int lef = id[B[i].first], rig = id[B[i].second];
        int v = head[B[i].first];
        int got = tr[v].Get(lef, rig, y);
        if (got >= k) {
            int res = inhead[v][tr[v].getInd(lef, rig, k, y)];
            return res == forb? -1: res;
        } else k -= got;
    }
    return -1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &P[i]);
        if (P[i]) neigh[P[i]].push_back(i);
        else root = i;
    }
    Traverse(root);
    head[root] = root; id[root] = 0;
    BuildHLD(root);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &typ[i], &qa[i]);
        if (typ[i] == 1)
            tr[head[qa[i]]].createAdd(id[qa[i]], i);
        else scanf("%d %d %d", &qb[i], &qk[i], &qy[i]);
    }
    for (int i = 1; i <= n; i++) if (head[i] == i)
        tr[i].postCreate();
    for (int i = 1; i <= m; i++)
        if (typ[i] == 1) {
            int old = cur[qa[i]];
            cur[qa[i]] = i;
            tr[head[qa[i]]].Update(id[qa[i]], old, cur[qa[i]]);
        } else printf("%d\n", Get(qa[i], qb[i], qk[i], qy[i]));
    return 0;
}