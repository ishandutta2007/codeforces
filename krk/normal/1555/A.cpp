#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        ll tims = (n - 1) / 10 + 1;
        ll res = tims * 15ll;
        n -= tims * 6ll;
        if (n > 0) {
            ll add = (n - 1) / 2 + 1;
            res += add * 5ll;
        }
        cout << res << "\n";
    }
    return 0;
}