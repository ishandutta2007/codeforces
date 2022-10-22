#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, y, z;

int main()
{
    cin >> x >> y >> z;
    ll res = x / z; x %= z;
    res += y / z; y %= z;
    ll res2 = 0;
    if ((x + y) >= z) {
        res++;
        res2 += z - max(x, y);
    }
    cout << res << " " << res2 << endl;
    return 0;
}