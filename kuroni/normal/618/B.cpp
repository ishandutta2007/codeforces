#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, a[N][N], ans[N];

bool check(int u, int v)
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i][v] != 0 && a[i][v] != u)
            return false;
        if (a[v][i] != 0 && a[v][i] != u)
            return false;
    }
    return true;
}

void clear(int u)
{
    for (int i = 1; i <= n; i++)
        a[i][u] = a[u][i] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (ans[j] == 0 && check(i, j))
            {
                ans[j] = i;
                clear(j);
                break;
            }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}