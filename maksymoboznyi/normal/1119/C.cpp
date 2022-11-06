#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 5e2 + 1;
int n, m, a[N][N], b[N][N];
int k1[N], k2[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] != b[i][j])
                k1[i] ++, k2[j]++;
    for (int i = 1; i <= n; i++)
    if (k1[i] % 2 != 0) {
        cout << "No";
        return 0;
    }
    for (int j = 1; j <= m; j++)
    if (k2[j] % 2 != 0) {
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}