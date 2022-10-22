#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;

int n;
int a[Maxn];
vector <int> st[Maxm];
int res[Maxn];

void Create(int v, int l, int r)
{
    if (l == r) st[v].push_back(a[l]);
    else {
        int m = l + r >> 1;
        int lc = 2 * v, rc = 2 * v + 1;
        Create(lc, l, m); Create(rc, m + 1, r);
        int i = 0, j = 0;
        while (i < st[lc].size() || j < st[rc].size())
            if (i < st[lc].size() && (j == st[rc].size() || st[lc][i] <= st[rc][j]))
                st[v].push_back(st[lc][i++]);
            else st[v].push_back(st[rc][j++]);
    }
}

int Get(int v, int l, int r, int a, int b, int x)
{
    if (l == a && r == b)
        return lower_bound(st[v].begin(), st[v].end(), x) - st[v].begin();
    else {
        int res = 0;
        int m = l + r >> 1;
        if (a <= m) res += Get(2 * v, l, m, a, min(m, b), x);
        if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b, x);
        return res;
    }
}

int Get(int a, int b, int x)
{
    if (b > n) b = n;
    if (a > b) return 0;
    return Get(1, 1, n, a, b, x);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Create(1, 1, n);
    for (int k = 1; k < n; k++) {
        int res = 0;
        for (int i = 1, j = 2; i <= n && j <= n; i++, j += k)
            res += Get(j, j + k - 1, a[i]);
        printf("%d%c", res, k + 1 < n? ' ': '\n');
    }
    return 0;
}