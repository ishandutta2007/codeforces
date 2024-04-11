#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

const LL INF = (LL)1e18;
const int N = 1000 + 10;

LL a[N][N];
LL dp11[N][N];
LL dp12[N][N];
LL dp21[N][N];
LL dp22[N][N];
LL res = 0;
int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            dp11[i][j] = dp12[i][j] = dp21[i][j] = dp22[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp11[i][j] = max(dp11[i - 1][j], dp11[i][j - 1]) + a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            dp12[i][j] = max(dp12[i - 1][j], dp12[i][j + 1]) + a[i][j];
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            dp21[i][j] = max(dp21[i + 1][j], dp21[i][j - 1]) + a[i][j];
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            dp22[i][j] = max(dp22[i + 1][j], dp22[i][j + 1]) + a[i][j];
    for (int i = 2; i < n; i++)
        for (int j = 2; j < m; j++)
        {
            res = max(res, dp11[i - 1][j] + dp22[i + 1][j] + dp21[i][j - 1] + dp12[i][j + 1]);
            res = max(res, dp11[i][j - 1] + dp22[i][j + 1] + dp21[i + 1][j] + dp12[i - 1][j]);
        }

    cout << res;

    return 0;
}