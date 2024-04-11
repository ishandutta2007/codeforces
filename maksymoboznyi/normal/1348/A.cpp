#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long
#define vi vector<int>
#define pi pair<int, int>

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
        int a1 = 0, a2 = 0;
        a2 += (1ll << n);
        for (int i = 1; i < n / 2; i++)
            a2 += (1ll << i);
        for (int i = n / 2; i < n; i++)
            a1 += (1ll << i);
        cout << abs(a1 - a2) << "\n";
    }
    return 0;
}