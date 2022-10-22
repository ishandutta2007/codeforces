#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Inf = 2000000007;

int n, m, p;
ii A[Maxn];
ii B[Maxn];
ii seqa[Maxn], seqb[Maxn];
int lena, lenb;
int st[Maxm], fl[Maxm];
iii mon[Maxn];
int res = -Inf;

bool Less(const ii &a, const ii &b)
{
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

void downOn(int v, int f)
{
    st[v] += f;
    fl[v] += f;
}

void Down(int v)
{
    if (fl[v]) {
        downOn(2 * v, fl[v]);
        downOn(2 * v + 1, fl[v]);
        fl[v] = 0;
    }
}

void Union(int v)
{
    st[v] = max(st[2 * v], st[2 * v + 1]);
}

void Create(int v, int l, int r)
{
    if (l == r) st[v] = -seqb[l].second;
    else {
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

int main()
{
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &A[i].first, &A[i].second);
    for (int i = 0; i < m; i++)
        scanf("%d %d", &B[i].first, &B[i].second);
    sort(A, A + n, Less);
    sort(B, B + m, Less);
    for (int i = 0; i < n; i++) {
        while (lena > 0 && seqa[lena - 1].second >= A[i].second) lena--;
        seqa[lena++] = A[i];
    }
    for (int i = 0; i < m; i++) {
        while (lenb > 0 && seqb[lenb - 1].second >= B[i].second) lenb--;
        seqb[lenb++] = B[i];
    }
    Create(1, 0, lenb - 1);
    for (int i = 0; i < p; i++)
        scanf("%d %d %d", &mon[i].first.first, &mon[i].first.second, &mon[i].second);
    sort(mon, mon + p);
    int pnt = 0;
    for (int i = 0; i < lena; i++) {
        while (pnt < p && mon[pnt].first.first < seqa[i].first) {
            int ind = lower_bound(seqb, seqb + lenb, ii(mon[pnt].first.second + 1, 0)) - seqb;
            if (ind < lenb) Update(1, 0, lenb - 1, ind, lenb - 1, mon[pnt].second);
            pnt++;
        }
        res = max(res, st[1] - seqa[i].second);
    }
    printf("%d\n", res);
    return 0;
}