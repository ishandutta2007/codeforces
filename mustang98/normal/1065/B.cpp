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
    ll n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }
    if (m == 0) {
        cout << n << ' ' << n << endl;
        return 0;
    }
    ll minn = max(0LL, n - 2 * m);
    ll maxx = 0;
    for (ll i = 1; i <= n; ++i) {
        ll cnt = (i * (i - 1)) / 2;
        if (cnt >= m) {
            maxx = n - i;
            break;
        }
    }
    cout << minn << ' ' << maxx << endl;

    return 0;
}