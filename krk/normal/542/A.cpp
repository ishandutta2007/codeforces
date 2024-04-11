#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 4194304;
const int Inf = 2000000000;

struct pos {
    int x, ind;
    bool typ;
    pos(int x = 0, int ind = 0, bool typ = false): 
        x(x), ind(ind), typ(typ) {}
    bool operator <(const pos &b) const {
        if (x != b.x) return x < b.x;
        return typ < b.typ;
    }
};

int n, m;
int L[Maxn], R[Maxn];
int A[Maxn], B[Maxn], C[Maxn];
vector <int> un;
vector <pos> seq;
ii st[Maxm], bef[Maxm], inb[Maxm];
ll best;
int bi, bj;

void Insert(ii st[], int v, int l, int r, int x, ii val)
{
    if (l == r) st[v] = max(st[v], val);
    else {
        int m = l + r >> 1;
        if (x <= m) Insert(st, 2 * v, l, m, x, val);
        else Insert(st, 2 * v + 1, m + 1, r, x, val);
        st[v] = max(st[2 * v], st[2 * v + 1]);
    }
}

ii Get(ii st[], int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        ii res = ii(0, 0);
        if (a <= m) res = max(res, Get(st, 2 * v, l, m, a, min(m, b)));
        if (m + 1 <= b) res = max(res, Get(st, 2 * v + 1, m + 1, r, max(m + 1, a), b));
        return res;
    }
}

void ICreate(ii st[], int v, int l, int r)
{
    st[v] = ii(Inf, -1);
    if (l < r) {
        int m = l + r >> 1;
        ICreate(st, 2 * v, l, m); ICreate(st, 2 * v + 1, m + 1, r);
    }
}

void IInsert(ii st[], int v, int l, int r, int a, int b, ii val)
{
    if (l == a && r == b) st[v] = min(st[v], val);
    else {
        int m = l + r >> 1;
        if (a <= m) IInsert(st, 2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) IInsert(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
    }
}

ii IGet(ii st[], int v, int l, int r, int x)
{
    ii res = st[v];
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) res = min(res, IGet(st, 2 * v, l, m, x));
        else res = min(res, IGet(st, 2 * v + 1, m + 1, r, x));
    }
    return res;
}

void Check(ll cand, int ci, int cj)
{
    if (cand > best) {
        best = cand; bi = ci; bj = cj;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &L[i], &R[i]);
        seq.push_back(pos(R[i], i, false));
        un.push_back(L[i]); un.push_back(R[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        seq.push_back(pos(B[i], i, true));
        un.push_back(A[i]); un.push_back(B[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    ICreate(st, 1, 0, un.size() - 1);
    for (int i = 1; i <= n; i++) {
        L[i] = lower_bound(un.begin(), un.end(), L[i]) - un.begin();
        R[i] = lower_bound(un.begin(), un.end(), R[i]) - un.begin();
        IInsert(st, 1, 0, un.size() - 1, L[i], R[i], ii(un[L[i]], i));
    }
    for (int i = 1; i <= m; i++) {
        A[i] = lower_bound(un.begin(), un.end(), A[i]) - un.begin();
        B[i] = lower_bound(un.begin(), un.end(), B[i]) - un.begin();
    }

    sort(seq.begin(), seq.end());
    for (int i = 0; i < seq.size(); i++) {
        pos p = seq[i];
        if (!p.typ) {
            Insert(bef, 1, 0, un.size() - 1, L[p.ind], ii(un[R[p.ind]], p.ind));
            Insert(inb, 1, 0, un.size() - 1, L[p.ind], ii(un[R[p.ind]] - un[L[p.ind]], p.ind));
        } else {
            ii got = IGet(st, 1, 0, un.size() - 1, B[p.ind]);
            ll cand = ll(C[p.ind]) * (un[B[p.ind]] - max(un[A[p.ind]], got.first));
            Check(cand, got.second, p.ind);
            got = Get(bef, 1, 0, un.size() - 1, 0, A[p.ind]);
            cand = ll(C[p.ind]) * (got.first - un[A[p.ind]]);
            Check(cand, got.second, p.ind);
            got = Get(inb, 1, 0, un.size() - 1, A[p.ind], B[p.ind]);
            cand = ll(C[p.ind]) * got.first;
            Check(cand, got.second, p.ind);
        }
    }
    printf("%I64d\n", best);
    if (best > 0) printf("%d %d\n", bi, bj);
    return 0;
}