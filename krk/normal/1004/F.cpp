#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 524288;
const int Maxk = 20;

struct node {
    ll sum;
    int mn;
    int cnt;
    int flag;
};

int n, m, x;
int a[Maxn], inr[Maxn];
set <int> S[Maxk];
node st[Maxm];
vector <ii> A, B;

void downOn(int v, int f)
{
    st[v].sum = ll(st[v].cnt) * f;
    st[v].mn = f;
    st[v].flag = f;
}

void Down(int v)
{
    if (st[v].flag) {
        downOn(2 * v, st[v].flag);
        downOn(2 * v + 1, st[v].flag);
        st[v].flag = 0;
    }
}

void Union(int v)
{
    int lc = 2 * v, rc = 2 * v + 1;
    st[v].sum = st[lc].sum + st[rc].sum;
    st[v].mn = st[lc].mn;
    st[v].cnt = st[lc].cnt + st[rc].cnt;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].sum = st[v].mn = inr[l];
        st[v].cnt = 1;
        st[v].flag = 0;
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int a, int b, int val)
{
    if (l == a && r == b) downOn(v, val);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        Union(v);
    }
}

ll getSum(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v].sum;
    else {
        Down(v);
        int m = l + r >> 1;
        ll res = 0;
        if (a <= m) res += getSum(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) res += getSum(2 * v + 1, m + 1, r, max(m + 1, a), b);
        return res;
    }
}

int getRight(int v, int l, int r, int val)
{
    if (st[v].mn > val) return l - 1;
    else if (l == r) return l;
    else {
        Down(v);
        int m = l + r >> 1;
        int got = getRight(2 * v + 1, m + 1, r, val);
        if (got > m) return got;
        return getRight(2 * v, l, m, val);
    }
}

vector <ii> getNext(int ind)
{
    vector <ii> res(Maxk);
    for (int i = 0; i < Maxk; i++) {
        auto it = S[i].lower_bound(ind);
        res[i] = ii((it == S[i].end()? n + 1: *it), i);
    }
    sort(res.begin(), res.end());
    return res;
}

vector <ii> getPrev(int ind)
{
    vector <ii> res(Maxk);
    for (int i = 0; i < Maxk; i++) {
        auto it = S[i].upper_bound(ind);
        if (it == S[i].begin())
            res[i] = ii(0, i);
        else {
            it--;
            res[i] = ii(*it, i);
        }
    }
    sort(res.rbegin(), res.rend());
    return res;
}

void tryUpdate(int lef, int rig, int val, int ind)
{
    if (lef > rig) return;
    int lst = ind;
    int pnt = 0;
    while (val < x) {
        val |= 1 << B[pnt].second;
        lst = B[pnt].first;
        pnt++;
    }
    Update(1, 1, n, lef, rig, lst);
}

int main()
{
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < Maxk; j++)
            if (a[i] & 1 << j) S[j].insert(i);
        vector <ii> seq(Maxk);
        for (int j = 0; j < Maxk; j++)
            seq[j] = ii((S[j].empty()? n + 1: *S[j].begin()), j);
        sort(seq.begin(), seq.end());
        int cur = 0;
        int pnt = 0, lst = i;
        while (cur < x) {
            cur |= 1 << seq[pnt].second;
            lst = seq[pnt].first;
            pnt++;
        }
        inr[i] = lst;
    }
    Create(1, 1, n);
    while (m--) {
        int typ, u, v; scanf("%d %d %d", &typ, &u, &v);
        if (typ == 1) {
            for (int i = 0; i < Maxk; i++) {
                bool was = (a[u] & 1 << i);
                bool nw = (v & 1 << i);
                if (!was && nw) S[i].insert(u);
                else if (was && !nw) S[i].erase(u);
            }
            a[u] = v;
            A = getPrev(u), B = getNext(u);
            int st = getRight(1, 1, n, u - 1);
            int curval = 0;
            tryUpdate(max(st, A[0].first) + 1, u, curval, u);
            for (int i = 0; i < A.size(); i++) {
                curval |= 1 << A[i].second;
                int lef = i + 1 < A.size()? max(st, A[i + 1].first) + 1: st + 1;
                int rig = A[i].first;
                tryUpdate(lef, rig, curval, u);
            }
        } else {
            int rig = getRight(1, 1, n, v);
            if (rig < u) printf("0\n");
            else {
                ll res = ll(rig - u + 1) * (v + 1) - getSum(1, 1, n, u, rig);
                printf("%I64d\n", res);
            }
        }
    }
    return 0;
}