#include<algorithm>
#include<cassert>
#include<cstdio>
#include<iostream>

using namespace std;

typedef long long ll;

ll n, a, b;

ll gcd(ll _a, ll _b)
{
    while (_b) {
        ll _c = _a % _b;
        _a = _b;
        _b = _c;
    }
    return _a;
}

int main()
{
    cin >> n >> a >> b;

    if (a == b) {
        cout << 1 << '/' << 1 << endl;
    } else {
        ll c = min(a, b), div = gcd(a, b);
        ll ans = min(n, c - 1);

        // if (lca >= n + 1)
        // if (a / div * b >= n + 1)
        // if (a / div >= (n + 1) / b)

        cerr << a << " " << div << " " << b << endl;
        cerr << (a / div) << " " << (n / b) << endl;

        if (a / div > n / b) {
            ll ddiv = gcd(ans, n);
            cout << (ans / ddiv) << '/' << (n / ddiv) << endl;
        } else {
            ll lca = a / div * b;
            assert(lca > 0);
            ll highest = n - (n % lca);
            ll lower = n - (n % lca) - lca;
            ll cnt = lower / lca * c;

            ll upto = min(n, highest + c - 1);
            ll extrasum = upto - highest + 1;

            cerr << ans << " " << cnt << " " << upto << " " << extrasum << endl;
            ans += cnt + extrasum;

            ll ddiv = gcd(ans, n);

            assert(ans > 0);
            cout << (ans / ddiv) << '/' << (n / ddiv) << endl;
        }
    }
    return 0;
}