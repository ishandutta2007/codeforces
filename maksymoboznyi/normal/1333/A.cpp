#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5 + 5;


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
        cout << 'W';
        for (int i = 1; i < m; i++)
            cout << 'B';
        cout << "\n";
        for (int i = 1; i < n; i++) {
            for (int j =1 ; j <= m; j++)
                cout << 'B';
            cout << "\n";
        }
    }
    return 0;
}