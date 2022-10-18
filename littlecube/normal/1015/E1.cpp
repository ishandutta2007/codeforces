#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int n, m, r = 0;
    char grid[105][105] = {{0}};
    int size[105][105] = {{0}};
    char new_grid[105][105] = {{0}};
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (grid[i][j] == '*')
                for (int k = 1; k < min(min(i, n - i + 1), min(j, m - j + 1)); k++)
                {
                    if (grid[i + k][j] == '*' && grid[i - k][j] == '*' && grid[i][j + k] == '*' && grid[i][j - k] == '*')
                        size[i][j] = k;
                    else
                        break;
                }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (size[i][j] != 0)
            {
                r++;
                new_grid[i][j] = '*';
                for (int k = 1; k <= size[i][j]; k++)
                {
                    new_grid[i + k][j] = '*';
                    new_grid[i - k][j] = '*';
                    new_grid[i][j + k] = '*';
                    new_grid[i][j - k] = '*';
                }
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (grid[i][j] == '*' && new_grid[i][j] != '*')
            {
                cout << -1;
                return 0;
            }
    cout << r << '\n';
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (size[i][j] != 0)
                cout << i << " " << j << " " << size[i][j] << '\n';
}