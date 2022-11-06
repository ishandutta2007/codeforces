#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
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
        int n;
        cin >> n;
        if (n == 44)
            cout << "YES\n" << "6 7 10 21\n";
        else
            if (n == 36)
                cout << "YES\n" << "5 6 10 15\n";
            else if (n == 40)
                cout << "YES\n" << "6 9 10 15\n";
            else
        if (n >= 31) {
            cout << "YES\n";
            cout << "14 10 6 " << n - 30 << "\n";
        } else
        cout << "NO\n";
    }
    return 0;
}