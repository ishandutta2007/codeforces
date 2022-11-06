#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 3e5 + 5;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {


        int n;
        cin >> n;
        int x = 1001;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1)
                x--;
            cout << x << ' ';
        }
        cout << "\n";
    }
    return 0;
}