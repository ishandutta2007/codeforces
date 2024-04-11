#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;

int n, m, k;
int row0[Maxn], row1[Maxn];
int col0[Maxn], col1[Maxn];
int fallrow, fallcol;
int byrow, bycol;
int vert, hor;
int has01, has10;
map <ii, int> M;

int Get(const ii &p)
{
    auto it = M.find(p);
    return it != M.end()? it->second: -1;
}

int waysRows() { return fallrow > 0? 0: byrow; }

int waysCols() { return fallcol > 0? 0: bycol; }

void removeRow(int r)
{
    if (row0[r] > 0 && row1[r] > 0)
        fallrow--;
    else if (row0[r] == 0 && row1[r] == 0)
        byrow = ll(byrow) * inv2 % mod;
}

void addRow(int r)
{
    if (row0[r] > 0 && row1[r] > 0)
        fallrow++;
    else if (row0[r] == 0 && row1[r] == 0) byrow = 2ll * byrow % mod;
}

void removeCol(int c)
{
    if (col0[c] > 0 && col1[c] > 0)
        fallcol--;
    else if (col0[c] == 0 && col1[c] == 0)
        bycol = ll(bycol) * inv2 % mod;
}

void addCol(int c)
{
    if (col0[c] > 0 && col1[c] > 0)
        fallcol++;
    else if (col0[c] == 0 && col1[c] == 0)
        bycol = 2ll * bycol % mod;
}

void Remove(const ii &p)
{
    int g = Get(p);
    if (g == -1) return;
    M.erase(p);
    removeRow(p.first);
    if ((p.second % 2 != 0) == (g == 1))
        row0[p.first]--;
    else row1[p.first]--;
    addRow(p.first);
    removeCol(p.second);
    if ((p.first % 2 != 0) == (g == 1))
        col0[p.second]--;
    else col1[p.second]--;
    addCol(p.second);
    if (((p.first + p.second) % 2 != 0) == (g == 1))
        has01--;
    else has10--;
    if (Get(ii(p.first - 1, p.second)) == g) vert--;
    if (Get(ii(p.first + 1, p.second)) == g) vert--;
    if (Get(ii(p.first, p.second - 1)) == g) hor--;
    if (Get(ii(p.first, p.second + 1)) == g) hor--; 
}

void Add(const ii &p, int g)
{
    M[p] = g;
    removeRow(p.first);
    if ((p.second % 2 != 0) == (g == 1))
        row0[p.first]++;
    else row1[p.first]++;
    addRow(p.first);
    removeCol(p.second);
    if ((p.first % 2 != 0) == (g == 1))
        col0[p.second]++;
    else col1[p.second]++;
    addCol(p.second);
    if (((p.first + p.second) % 2 != 0) == (g == 1))
        has01++;
    else has10++;
    if (Get(ii(p.first - 1, p.second)) == g) vert++;
    if (Get(ii(p.first + 1, p.second)) == g) vert++;
    if (Get(ii(p.first, p.second - 1)) == g) hor++;
    if (Get(ii(p.first, p.second + 1)) == g) hor++; 
}

int getWays()
{
    int res = 0;
    if (hor == 0) res = (res + waysRows()) % mod;
    if (vert == 0) res = (res + waysCols()) % mod;
    res -= (2 - (has01 > 0) - (has10 > 0));
    if (res < 0) res += mod;
    return res;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    byrow = bycol = 1;
    for (int i = 0; i < n; i++)
        byrow = 2ll * byrow % mod;
    for (int i = 0; i < m; i++)
        bycol = 2ll * bycol % mod;
    for (int i = 0; i < k; i++) {
        int x, y, typ; scanf("%d %d %d", &x, &y, &typ);
        Remove(ii(x, y));
        if (typ != -1)
            Add(ii(x, y), typ);
        printf("%d\n", getWays());
    }
    return 0;
}