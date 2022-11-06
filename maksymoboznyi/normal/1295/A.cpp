#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N = 3e5 + 5;
const long long M = 1e9 + 7;
const long long inf = 1e18;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t) {
        t--;
        int n;
        cin >> n;
        if (n % 2 == 0) {
            for (int i = 0; i < n / 2; i++)
                cout << 1;
            cout << "\n";
        } else {
            cout << 7;
            n -= 3;
            for (int i = 0; i < n / 2; i++)
                cout << 1;
            cout << "\n";
        }
    }
    return 0;
}