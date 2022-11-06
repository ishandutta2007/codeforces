#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

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
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (2 * a <= b)
            cout << (x + y) * a;
        else
            cout << min(x, y) * b + (x + y - 2 * min(x, y)) * a;
        cout << "\n";
    }
    return 0;
}