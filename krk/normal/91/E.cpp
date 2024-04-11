#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, int> lli;

const int Maxn = 100005;
const int Maxm = 524288;

int n, q;
int A[Maxn], B[Maxn];
int seq[Maxn];
vector <ii> lins[Maxm], X[Maxm];
int pnt[Maxm];
int L[Maxn], R[Maxn], T[Maxn];
ii my[Maxn];
int res[Maxn];

bool Less(const int &a, const int &b)
{
    if (B[a] != B[b]) return B[a] < B[b];
    return A[a] < A[b];
}

int getX(const ii &fir, const ii &sec)
{
    if (fir.first <= sec.first) return 0;
    return (fir.first - sec.first - 1) / (sec.second - fir.second) + 1;
}

void Add(int v, const ii &p, int ind)
{
    while (!lins[v].empty() && lins[v].back().first <= p.first) {
        lins[v].pop_back(); X[v].pop_back();
    }
    while (lins[v].size() >= 2) {
        int x = getX(lins[v].back(), p);
        if (x <= X[v].back().first) {
            lins[v].pop_back();
            X[v].pop_back();
        } else break;
    }
    if (X[v].empty()) X[v].push_back(ii(0, ind));
    else X[v].push_back(ii(getX(lins[v].back(), p), ind));
    lins[v].push_back(p);
}

lli Get(int v, int x)
{
    while (pnt[v] + 1 < lins[v].size() && x >= X[v][pnt[v] + 1].first)
        pnt[v]++;
    return lli(ll(lins[v][pnt[v]].first) + ll(lins[v][pnt[v]].second) * x, X[v][pnt[v]].second);
}

void Insert(int v, int l, int r, int x, int a, int b)
{
    Add(v, ii(a, b), x);
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) Insert(2 * v, l, m, x, a, b);
        else Insert(2 * v + 1, m + 1, r, x, a, b);
    }
}

lli Get(int v, int l, int r, int a, int b, int t)
{
    if (l == a && r == b)
        return Get(v, t);
    else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b, t);
        else if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b, t);
        else return max(Get(2 * v, l, m, a, m, t), Get(2 * v + 1, m + 1, r, m + 1, b, t));
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &A[i], &B[i]);
        seq[i - 1] = i;
    }
    sort(seq, seq + n, Less);
    for (int i = 0; i < n; i++) {
        int ind = seq[i];
        Insert(1, 1, n, ind, A[ind], B[ind]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &L[i], &R[i], &T[i]);
        my[i] = ii(T[i], i);
    }
    sort(my, my + q);
    for (int i = 0; i < q; i++) {
        int ind = my[i].second;
        res[ind] = Get(1, 1, n, L[ind], R[ind], T[ind]).second;
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", res[i]);
    return 0;
}