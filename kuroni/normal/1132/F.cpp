#include <iostream>
#include <cstdio>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int N = 505;

int n;
pair<int, int> f[N][N];
char s[N];

pair<int, int> mini(pair<int, int> a, pair<int, int> b)
{
    if (a.fi < b.fi)
        return a;
    else if (b.fi < a.fi)
        return b;
    else
        return mp(a.fi, a.se | b.se);
}

pair<int, int> combine(pair<int, int> a, pair<int, int> b)
{
    if (a.se & b.se)
        return mp(a.fi + b.fi, a.se & b.se);
    else
        return mp(a.fi + b.fi + 1, a.se | b.se);
}

int value(int u, pair<int, int> v)
{
    return (v.se >> u & 1) ? v.fi : v.fi + 1;
}

int main()
{
    scanf("%d\n%s", &n, s + 1);
    n = distance(s + 1, unique(s + 1, s + n + 1));
    for (int l = n; l >= 1; l--)
    {
        f[l][l] = mp(0, 1 << (s[l] - 'a'));
        for (int r = l + 1; r <= n; r++)
        {
            f[l][r] = mp(N, 0);
            for (int k = l; k < r; k++)
                f[l][r] = mini(f[l][r], combine(f[l][k], f[k + 1][r]));
        }
    }
    printf("%d", f[1][n].fi + 1);
}