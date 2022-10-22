#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Inf = 2000000007;
const int lim = 1000000002;

int q;
int qtyp[Maxn], qa[Maxn], qb[Maxn], qc[Maxn];
vector <int> un;
ll mn[Maxm], sum[Maxm], lst[Maxm];
ll fl[Maxm];
map <int, int> M;

void downOn(int v, int l, int r, ll f)
{
    fl[v] = f;
    mn[v] = f >= 0? 0: (un[r] - un[l]) * f;
    sum[v] = (un[r] - un[l]) * f;
    lst[v] = f;
}

void Down(int v, int l, int m, int r)
{
    if (fl[v] != Inf) {
        downOn(2 * v, l, m, fl[v]);
        downOn(2 * v + 1, m + 1, r, fl[v]);
        fl[v] = Inf;
    }
}

void Union(int v, int m)
{
    int lc = 2 * v, rc = 2 * v + 1;
    mn[v] = min(mn[lc], sum[lc] + lst[lc] * (un[m + 1] - un[m]) + mn[rc]);
    sum[v] = sum[lc] + lst[lc] * (un[m + 1] - un[m]) + sum[rc];
    lst[v] = lst[rc];
}

void Create(int v, int l, int r)
{
    fl[v] = Inf;
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
    }
}

void Update(int v, int l, int r, int a, int b, ll x)
{
    if (l == a && r == b) downOn(v, l, r, x);
    else {
        int m = l + r >> 1;
        Down(v, l, m, r);
        if (a <= m) Update(2 * v, l, m, a, min(m, b), x);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, x);
        Union(v, m);
    }
}

ld Solve(int v, int l, int r, int a, int b, ll &lft)
{
    if (l == a && r == b && lft + mn[v] > 0) { lft += sum[v]; return -1; }
    else {
        int m = l + r >> 1;
        Down(v, l, m, r);
        if (b <= m) return Solve(2 * v, l, m, a, b, lft);
        if (m + 1 <= a) return Solve(2 * v + 1, m + 1, r, a, b, lft);
        ld got = Solve(2 * v, l, m, a, m, lft);
        if (got != -1) return got;
        lft += lst[2 * v] * (un[m + 1] - un[m]);
        if (lft <= 0) return un[m + 1] - lft / ld(lst[2 * v]);
        return Solve(2 * v + 1, m + 1, r, m + 1, b, lft);
    }
}

int main()
{
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &qtyp[i], &qa[i]);
        if (qtyp[i] == 1) {
            scanf("%d", &qb[i]);
            un.push_back(qa[i]);
        } else if (qtyp[i] == 3) {
            scanf("%d %d", &qb[i], &qc[i]);
            un.push_back(qa[i]);
            un.push_back(qb[i]);
        }
    }
    un.push_back(0);
    M[0] = 0;
    un.push_back(lim);
    M[lim] = 0;
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    Create(1, 0, int(un.size()) - 1);
    for (int i = 0; i < q; i++)
        if (qtyp[i] == 1) {
            int lef = lower_bound(un.begin(), un.end(), qa[i]) - un.begin();
            int rig = lower_bound(un.begin(), un.end(), M.upper_bound(qa[i])->first) - un.begin();
            Update(1, 0, int(un.size()) - 1, lef, rig - 1, qb[i]);
            M[qa[i]] = qb[i];
        } else if (qtyp[i] == 2) {
            auto it = M.find(qa[i]);
            M.erase(it++);
            int rig = lower_bound(un.begin(), un.end(), it->first) - un.begin();
            it--;
            int lef = lower_bound(un.begin(), un.end(), it->first) - un.begin();
            Update(1, 0, int(un.size()) - 1, lef, rig - 1, it->second);
        } else if (qtyp[i] == 3) {
            if (qc[i] == 0) { printf("%d\n", qa[i]); continue; }
            auto it = M.lower_bound(qa[i]);
            if (it == M.end() || it->first > qb[i]) { printf("-1\n"); continue; }
            int na = it->first;
            it = M.upper_bound(qb[i]);
            it--;
            int nb = it->first;
            int lef = lower_bound(un.begin(), un.end(), na) - un.begin();
            int rig = lower_bound(un.begin(), un.end(), nb) - un.begin();
            ll lft = qc[i];
            ld res = Solve(1, 0, int(un.size()) - 1, lef, rig, lft);
            if (res == -1) {
                lft += ll(it->second) * (qb[i] - nb);
                if (lft <= 0) res = qb[i] - lft / ld(it->second);
            }
            if (res == -1) printf("-1\n");
            else printf("%.9f\n", double(res));
        }
    return 0;
}