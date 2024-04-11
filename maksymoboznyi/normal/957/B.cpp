#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 55;
const long long inf = 2e18;

int n, m;
char a[N][N], b[N][N];
int x[N], y[N];
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j], a[i][j] = b[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '#')
                for (int k = j+1; k <= m; k++)
                    if (a[i][k] == '#')
                    {
                        for (int i1 = 1; i1 <= n; i1++)
                            if (a[i1][j] != a[i1][k])
                            {
                                cout << "No";
                                return 0;
                            }
                    }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            if (a[j][i] == '#')
                for (int k = j+1; k <= n; k++)
                    if (a[k][i] == '#')
                    {
                        for (int i1 = 1; i1 <= m; i1++)
                            if (a[j][i1] != a[k][i1])
                            {
                                cout << "No";
                                return 0;
                            }
                    }
    }
    cout << "Yes";
    return 0;
}