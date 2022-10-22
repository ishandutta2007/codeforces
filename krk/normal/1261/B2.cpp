#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxs = 1048576;

int n;
int a[Maxn];
ii seq[Maxn];
int q;
int qa[Maxn], qb[Maxn];
ii quer[Maxn];
int res[Maxn];
int st[Maxs];

void Add(int v, int l, int r, int x)
{
    st[v]++;
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) Add(2 * v, l, m, x);
        else Add(2 * v + 1, m + 1, r, x);
    }
}

int Get(int v, int l, int r, int ind)
{
    if (l == r) return a[l];
    else {
        int m = l + r >> 1;
        if (ind <= st[2 * v]) return Get(2 * v, l, m, ind);
        else return Get(2 * v + 1, m + 1, r, ind - st[2 * v]);
    }
}

bool Less(const ii &a, const ii &b)
{
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        seq[i] = ii(a[i], i);
    }
    sort(seq, seq + n, Less);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &qa[i], &qb[i]);
        quer[i] = ii(qa[i], i);
    }
    sort(quer, quer + q);
    int pnt = 0;
    for (int i = 0; i < q; i++) {
        int ind = quer[i].second;
        while (pnt < qa[ind]) {
            int ind2 = seq[pnt].second;
            Add(1, 0, n - 1, ind2);
            pnt++;
        }
        res[ind] = Get(1, 0, n - 1, qb[ind]);
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", res[i]);
    return 0;
}