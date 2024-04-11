#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 3e3 + 1;
const int M = 998244353;

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
        int val = 2, can = 0;
        while (val * 2 - 1 <= n) {
            val *= 2;
            if (n % (val - 1) == 0) {
                cout << n / (val - 1) << "\n";
                can = 1;
                break;
            }
        }
    }
    return 0;
}