#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;
const long long inf = 2e18;



signed main()
{/*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin >> t;
    for (int o = 0; o < t; o++) {
        long long n, k;
        cin >> n >> k;
        if (n >= 33) {
            cout << "YES " << n - 1;
            cout << "\n";
            continue;
        }
        long long ko = 0, r = 0;
        for (int i = 1; i <= n; i++) {
            ko *= 4, ko++;
            if (ko >= k) {
                r = 1;
                break;
            }
        }
        if (!r) {
            cout << "NO\n";
            continue;
        }
        long long len = 1, ans = n;
        while (ans >= 1) {
            if (k < len) {
                break;
            }
            k -= len;
            ans--;
            len = len* 2 + 1;
        }
        long long a = 1, l = 1;
        if (ans == n - 1) {
            int kol = 1, sz = n - 1;
            while (sz > 0) {
                k -= kol;
                kol *= 4;
                sz--;
                if (k <= 0)
                    break;
            }
            if (k > 0)
            {
                cout << "NO\n";
                continue;
            }
        }
        cout << "YES " << ans << "\n";
    }
    return 0;
}