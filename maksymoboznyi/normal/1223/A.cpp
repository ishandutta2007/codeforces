#include <bits/stdc++.h>
#define pb push_back
#define ll long long


using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> n;
        if (n == 2) {
            cout << "2\n";
            continue;
        }
        if (n % 2 == 0)
            cout << 0 << "\n";
        else
            cout << 1 << "\n";
    }
    return 0;
}