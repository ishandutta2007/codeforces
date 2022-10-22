#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, p, w, d;

int main()
{
    cin >> n >> p >> w >> d;
    for (ll y = 0; y < w && y * d <= p; y++) {
        ll lft = p - y * d;
        if (lft % w == 0) {
            ll x = lft / w;
            if (x + y <= n) { printf("%I64d %I64d %I64d\n", x, y, n - x - y); return 0; }
        }
    }
    printf("-1\n");
    return 0;
}