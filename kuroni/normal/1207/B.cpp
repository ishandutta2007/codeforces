#include <bits/stdc++.h>
using namespace std;

const int M = 55, N = 55;

int m, n, a[M][N], b[M][N];
vector<pair<int, int>> ve;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1 && a[i - 1][j] == 1 && a[i][j - 1] == 1 && a[i - 1][j - 1] == 1)
            {
                b[i][j] = b[i - 1][j] = b[i][j - 1] = b[i - 1][j - 1] = 1;
                ve.push_back({i - 1, j - 1});
            }
        }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] != b[i][j])
                return cout << -1, 0;
    cout << ve.size() << '\n';
    for (pair<int, int> &v : ve)
        cout << v.first << " " << v.second << '\n';
}