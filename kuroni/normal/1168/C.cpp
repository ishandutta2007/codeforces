#include <bits/stdc++.h>
using namespace std;

const int N = 300005, LG = 19;

int n, q, x, y, a[N], lst[LG], nxt[N][LG];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    fill(nxt[n + 1], nxt[n + 1] + LG, n + 1);
    fill(lst, lst + LG, n + 1);
    for (int i = n; i >= 1; i--)
    {
        fill(nxt[i], nxt[i] + LG, n + 1);
        for (int j = 0; j < LG; j++)
            if (a[i] >> j & 1)
            {
                for (int k = 0; k < LG; k++)
                    nxt[i][k] = min(nxt[i][k], nxt[lst[j]][k]);
                nxt[i][j] = i;
            }
        for (int j = 0; j < LG; j++)
            if (a[i] >> j & 1)
                lst[j] = i;
    }
    while (q--)
    {
        cin >> x >> y;
        bool ok = false;
        for (int i = 0; !ok && i < LG; i++)
            if ((a[y] >> i & 1) && nxt[x][i] <= y)
                ok = true;
        cout << (ok ? "Shi\n" : "Fou\n");
    }
}