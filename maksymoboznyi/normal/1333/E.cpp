#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 505;

const int d[4][4] = {4, 3, 6, 12, 7, 5, 9, 15, 14, 1, 11, 10, 13, 8, 16, 2};

int n, a[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n == 3) {
        cout << "1 2 8\n7 3 6\n4 5 9";
        return 0;
    }
    if (n < 4) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            a[i][j] = d[i - 1][j - 1];
    for (int k = 5; k <= n; k++){
        for (int i = 1; i < k; i++)
            for (int j = 1; j < k; j++)
                a[i][j] += 2 * k - 1;
        if (k == 5) {
            for (int i = 1; i <= 5; i++)
                a[i][5] = i;
            a[5][1] = 8;
            a[5][2] = 9;
            a[5][3] = 7;
            a[5][4] = 6;
        } else
        if (k % 2 == 0){
            for (int i = 1; i <= k; i++)
                a[k][i] = i;
            for (int i = k; i > 0; i--)
                a[i][k] = k + (k - i);
        } else {
            for (int i = 1; i <=  k; i++)
                a[i][k] = i;
            for (int i = k; i > 0; i--)
                a[k][i] = k + (k - i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] <<  ' ';
        cout << "\n";
    }
    return 0;
}