#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

char a[10][10];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 1; i < 10; i++)
        for (int j = 1; j < 10; j++) {
            cin >> a[i][j];
            if (a[i][j] == '1')
                a[i][j] = '2';
        }
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 10; j++)
                cout << a[i][j];
            cout << "\n";
        }

    }
    return 0;
}