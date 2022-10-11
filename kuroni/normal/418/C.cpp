#include <bits/stdc++.h>
using namespace std;
    
const int M = 105, N = 105;
    
int m, n, a[M][N];
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    if (m == 1 && n == 1)
        return cout << 1, 0;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            a[i][j] = 16;
    for (int i = 1; i < n; i++)
        a[m][i] = (m == 1 ? 16 : 16 * (m - 1) - 4);
    for (int i = 1; i < m; i++)
        a[i][n] = (n == 1 ? 16 : 16 * (n - 1) - 4);
    if (m > 1 && n > 1)
        a[m][n] = 1LL * a[m][1] / 4 * a[1][n] / 4;
    else
    {
        int tmp = max(m, n) - 1;
        a[m][n] = 16 * tmp - 4;
    }
    for (int i = 1; i <= m; i++, cout << '\n')
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
}