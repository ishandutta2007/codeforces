#include <bits/stdc++.h>

using namespace std;

const int N = 2000 * 1000;

int val[N];
int hh[N];

void build(int i, int l, int r)
{
    val[i] = 0;
    if (l == r)
    {
        hh[i] = 0;
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    hh[i] = hh[2 * i + 1] + 1;
}

void put(int i, int p, int tl, int tr, int x)
{
    if (tl == tr)
    {
        val[i] = x;
        return;
    }
    int m = (tl + tr) / 2;
    if (p <= m)
        put(2 * i + 1, p, tl, m, x);
    else
        put(2 * i + 2, p, m + 1, tr, x);
    if (hh[i] % 2)
        val[i] = (val[2 * i + 1] | val[2 * i + 2]);
    else
        val[i] = (val[2 * i + 1] ^ val[2 * i + 2]);
}

int main()
{

    ios_base::sync_with_stdio(0);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    n = (1 << n);
    build(0, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        put(0, i, 0, n - 1, a);
    }
    for (int i = 0; i < m; i++)
    {
        int p, q;
        cin >> p >> q;
        --p;
        put(0, p, 0, n - 1, q);
        cout << val[0] << "\n";
    }

    return 0;
}