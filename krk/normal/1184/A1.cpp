#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll r;

int main()
{
    cin >> r;
    for (ll x = 1; x <= 1000000; x++) {
        ll rem = r - x * x - x - 1ll;
        if (rem <= 0 || rem % (2 * x)) continue;
        rem /= (2 * x);
        cout << x << " " << rem << endl;
        return 0;
    }
    cout << "NO\n";
    return 0;
}