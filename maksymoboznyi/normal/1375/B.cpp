#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 305;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int n, m, a[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        bool can = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                int kol = 4;
                if (i == 1 || i == n)
                    kol--;
                if (j == 1 || j == m)
                    kol--;
                cin >> a[i][j];
                if (a[i][j] > kol)
                    can = 0;
                else
                    a[i][j] = kol;
            }
        if (!can)
            cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++)
                     cout << a[i][j] << ' ';
                cout << "\n";
            }
        }
    }
    return 0;
}