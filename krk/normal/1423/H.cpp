#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;

int n, q, k;
int par[Maxn], siz[Maxn];
ii seq[Maxn];
int slen;
int pnt;
int cur;
int A[Maxn], B[Maxn];
int oth[Maxn];
vector <int> my[Maxn];

int getPar(int x) { return par[x] == x? x: getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    seq[slen++] = ii(a, b);
}

void Undo(int lim)
{
    while (slen > lim) {
        slen--;
        int a = seq[slen].first, b = seq[slen].second;
        siz[a] -= siz[b]; par[b] = b;
    }
}

void Solve(int l, int r)
{
    if (l == r) {
        if (oth[l] == l)
            printf("%d\n", siz[getPar(A[l])]);
    } else {
        int sz = slen;
        int m = l + r >> 1;
        for (int i = m + 1; i <= r; i++)
            if (oth[i] <= l) unionSet(A[i], B[i]);
        Solve(l, m);
        Undo(sz);
        for (int i = l; i <= m; i++)
            if (oth[i] > r) unionSet(A[i], B[i]);
        Solve(m + 1, r);
        Undo(sz);
    }
}

int main()
{
    scanf("%d %d %d", &n, &q, &k);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
    while (q--) {
        int typ; scanf("%d", &typ);
        if (typ == 1) {
            scanf("%d %d", &A[pnt], &B[pnt]);
            my[cur].push_back(pnt);
            pnt++;
        } else if (typ == 2) {
            scanf("%d", &A[pnt]);
            oth[pnt] = pnt;
            pnt++;
        } else {
            cur++;
            if (cur - k >= 0)
                for (int i = 0; i < my[cur - k].size(); i++) {
                    int ind = my[cur - k][i];
                    A[pnt] = A[ind]; B[pnt] = B[ind];
                    oth[pnt] = ind;
                    oth[ind] = pnt;
                    pnt++;
                }
        }
    }
    for (int t = max(0, cur - k + 1); t <= cur; t++)
        for (int i = 0; i < my[t].size(); i++) {
            int ind = my[t][i];
            A[pnt] = A[ind]; B[pnt] = B[ind];
            oth[pnt] = ind;
            oth[ind] = pnt;
            pnt++;
        }
    Solve(0, pnt - 1);
    return 0;
}