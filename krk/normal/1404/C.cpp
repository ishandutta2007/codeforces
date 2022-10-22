#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;
const int Maxm = 2097152;

int n, q;
int a[Maxn];
vector <int> inds[Maxn];
int st[Maxm];
vector <ii> seq;
int qa[Maxn], qb[Maxn];
vector <ii> quer;
int res[Maxn];

void Clear(int v, int l, int r)
{
    st[v] = 0;
    if (l < r) {
        int m = l + r >> 1;
        Clear(2 * v, l, m);
        Clear(2 * v + 1, m + 1, r);
    }
}

int Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int res = 0;
        int m = l + r >> 1;
        if (a <= m) res += Get(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
        return res;
    }
}

void Add(int v, int l, int r, int x)
{
    st[v]++;
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) Add(2 * v, l, m, x);
        else Add(2 * v + 1, m + 1, r, x);
    }
}

int getLeft(int v, int l, int r, int cnt)
{
    if (l == r) return l;
    else {
        int m = l + r >> 1;
        if (st[2 * v + 1] >= cnt)
            return getLeft(2 * v + 1, m + 1, r, cnt);
        else return getLeft(2 * v, l, m, cnt - st[2 * v + 1]);
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] = i - a[i];
        if (a[i] < 0 || st[1] < a[i]) continue;
        int val = a[i] == 0? i: getLeft(1, 1, n, a[i]);
        seq.push_back(ii(val, i));
        Add(1, 1, n, val);
    }
    sort(seq.rbegin(), seq.rend());
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &qa[i], &qb[i]);
        quer.push_back(ii(qa[i], i));
    }
    sort(quer.rbegin(), quer.rend());
    Clear(1, 1, n);
    int pnt = 0;
    for (int i = 0; i < quer.size(); i++) {
        int ind = quer[i].second;
        while (pnt < seq.size() && seq[pnt].first > qa[ind]) {
            int ind2 = seq[pnt].second;
            Add(1, 1, n, ind2);
            pnt++;
        }
        res[ind] = Get(1, 1, n, qa[ind] + 1, n - qb[ind]);
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", res[i]);
    return 0;
}