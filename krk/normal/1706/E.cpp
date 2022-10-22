#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxk = 20;

int T;
int n, m, q;
int par[Maxn];
set <int> S[Maxn];
int mx[Maxn][Maxk];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b, int w)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (S[a].size() < S[b].size()) swap(a, b);
    for (auto v: S[b]) {
        if (S[a].find(v + 1) != S[a].end())
            mx[v][0] = w;
        if (S[a].find(v - 1) != S[a].end())
            mx[v - 1][0] = w;
    }
    for (auto v: S[b])
        S[a].insert(v);
    S[b].clear();
    par[b] = a;
}

int getMax(int l, int r)
{
    int res = 0;
    for (int i = Maxk - 1; i >= 0; i--)
        if (l + (1 << i) <= r) {
            res = max(res, mx[l][i]);
            l += 1 << i;
        }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &q);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            S[i].clear();
            S[i].insert(i);
        }
        for (int i = 1; i <= m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            unionSet(a, b, i);
        }
        for (int j = 1; j < Maxk; j++)
            for (int i = 1; i + (1 << j) <= n; i++)
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
        for (int i = 1; i <= q; i++) {
            int l, r; scanf("%d %d", &l, &r);
            printf("%d%c", getMax(l, r), i + 1 <= q? ' ': '\n');
        }
    }
    return 0;
}