#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 301 + 6;

char a[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int x = k / n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = 0;
        for (int o = 0; o < x; o++) {
            for (int i = 1; i <= n; i++)
                if (i + o <= n)
                    a[i][o + i] = 1;
                else
                    a[i][o + i - n] = 1;
        }
        int s = k % n;
        if (s != 0) {
            a[1][n] = 1;
            s--;
        }
        if (s != 0) {
            for (int i = 2; i <= s + 1; i++)
                a[i][i - 1] = 1;
        }
        if (k % n == 0)
            cout << "0\n";
        else
            cout << "2\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cout << char(a[i][j] + 48);
            cout << "\n";
        }
    }
    return 0;
}