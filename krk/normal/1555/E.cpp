#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 300005;
const int Maxm = 2097152;
const int Inf = 1000000000;

int n, m;
iii seq[Maxn];
int st[Maxm], fl[Maxm];
map <ii, int> S;
int all;
map <int, int> M;
int res = 1000000000;

void Create(int v, int l, int r)
{
    st[v] = fl[v] = -Inf;
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
    }
}

void downOn(int v, int f)
{
    st[v] = max(st[v], f);
    fl[v] = max(fl[v], f);
}

void Down(int v)
{
    downOn(2 * v, fl[v]);
    downOn(2 * v + 1, fl[v]);
}

void Union(int v)
{
    st[v] = min(st[2 * v], st[2 * v + 1]);
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
    scanf("%d %d", &n, &m);
    Create(1, 1, m - 1);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &seq[i].second.first, &seq[i].second.second, &seq[i].first);
    sort(seq, seq + n);
    for (int i = 0; i < n; i++) {
        Update(1, 1, m - 1, seq[i].second.first, seq[i].second.second - 1, seq[i].first);
        res = min(res, seq[i].first - st[1]);
    }
    printf("%d\n", res);
    return 0;
}