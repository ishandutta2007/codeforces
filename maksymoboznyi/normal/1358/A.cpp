#include <bits/stdc++.h>
#define pb push_back
#define int long long
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
        int n, m;
        cin >> n >> m;
        if (n % 2 == 0 || m % 2 == 0)
            cout << n * m / 2 << "\n";
        else
            cout << n * m / 2 + 1 << "\n";
    }
    return 0;
}