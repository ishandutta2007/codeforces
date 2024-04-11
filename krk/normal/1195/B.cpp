#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;

int main()
{
    cin >> n >> k;
    ll nd = (k + n) * 2ll;
    for (ll i = 1; i * i <= nd; i++) if (nd % i == 0) {
        ll b = nd / i;
        if (i + 3 == b) { cout << n - i << endl; return 0; }
    }
    return 0;
}