#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 400005;
const int Maxm = 2097152;

int n, k, m;
int st[Maxm], fl[Maxm];
set <ii> S;
map <int, int> M;

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
    if (l == r) st[v] = l - 1;
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int a, int b, int delt)
{
    if (l == a && r == b) downOn(v, delt);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        Union(v);
    }
}

int Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        Down(v);
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        return max(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

int main()
{
    scanf("%d %d %d", &n, &k, &m);
    Create(1, 1, 2 * n);
    while (m--) {
        int x, y; scanf("%d %d", &x, &y);
        if (S.find(ii(x, y)) == S.end()) {
            S.insert(ii(x, y));
            int ind = abs(k - x) + y;
            Update(1, 1, 2 * n, 1, ind, 1);
            M[ind]++;
        } else {
            S.erase(ii(x, y));
            int ind = abs(k - x) + y;
            Update(1, 1, 2 * n, 1, ind, -1);
            if (--M[ind] == 0) M.erase(ind);
        }
        int nd = n;
        if (!M.empty()) nd = max(nd, Get(1, 1, 2 * n, 1, M.rbegin()->first));
        printf("%d\n", nd - n);
    }
    return 0;
}