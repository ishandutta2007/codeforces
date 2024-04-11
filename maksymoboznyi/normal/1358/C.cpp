#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 2e5 + 5;

int n, a[N];

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
        a = c - a;
        b = d - b;
        c = min(a, b);
        d = a + b - 1;
        //cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
        if (c == 0) {
            cout << "1\n";
            continue;
        }
        d -= c + c - 1;
        int ans = c * (c + 1) - c;
        cout << ans + d * c + 1 << "\n";
    }
    return 0;
}