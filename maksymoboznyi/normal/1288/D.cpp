#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int M = 300;

int a[N][10], best[M], n, m;

int f(int i, int mask) {
    int mn = 1e9 + 9;
    for (int j = 0; j < m; j ++)
        if ((mask >> j) & 1)
            mn = min(mn, a[i][j]);
    return mn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int mask = 0; mask < (1 << m); mask++)
        best[mask] = 0;
    for (int i = 1; i < n; i++)
        for (int mask = 0; mask < (1 << m); mask++)
            if (f(best[mask], mask) < f(i, mask))
                best[mask] = i;
    int ans, p1, p2;
    p1 = p2 = 0;
    ans = f(0, (1 << m) - 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int mask = 0;
            for (int k = 0; k < m; k++)
                if (a[i][k] < a[i][j])
                    mask ^= (1 << k);
            //if (i == 5 && best[mask] == 0)
            //cout << f(best[mask], mask) <<  ' ' << a[i][j] << ' ' << ans << endl;
            if (f(best[mask], mask) >= a[i][j] && a[i][j] >= ans)
                p1 = i, p2 = best[mask], ans = a[i][j];
        }
    cout << p1 + 1 << ' ' << p2 + 1;// << ' ' << ans;
    return 0;
}