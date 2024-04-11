#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    while(q--) {
        ll k, n, a, b;
        cin >> k >> n >> a >> b;
        ll mxc = (k - 1) / b;
        if (mxc < n) {
            cout << -1 << "\n";
            continue;
        }
        ll l = 0, r = n + 1;
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if (mid * a + (n - mid) * b < k) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << "\n";
    }


    return 0;
}