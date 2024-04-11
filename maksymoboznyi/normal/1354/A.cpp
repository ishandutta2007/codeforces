#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(q) (q).begin(), (q).end()
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b >= a) {
            cout << b << "\n";
            continue;
        }
        if (c <= d) {
            cout << "-1\n";
            continue;
        }
        a -= b;
        int kol = (a - 1) / (c - d) + 1;
        cout << b + kol * c << "\n";
    }
    return 0;
}