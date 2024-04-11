#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 2e5 + 5;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, a = 0, b = 0;
        cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            int q;
            cin >> q;
            if (q % 2 == 0)
                a++;
            else
                b++;
        }
        if (b == 0) {
            cout << "No\n";
            continue;
        }
        if (a >= x - 1) {
            cout << "Yes\n";
            continue;
        }
        b--;
        x--;

        ///x for chet

        if ((x - a) % 2 == 0) {
            if (b >= x - a)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }
        if (a >= 1) {
            if (b >= x - a + 1)
                cout << "Yes\n";
            else
                cout << "No\n";
        } else
            cout << "No\n";
    }
    return 0;
}