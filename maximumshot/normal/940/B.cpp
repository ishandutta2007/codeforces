#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll n, k, a, b;

    ll res = 0;

    cin >> n >> k >> a >> b;

    if(k == 1) {
        cout << (n - 1) * a << "\n";
        return 0;
    }

    while(n > 1) {
        if(n < k) {
            res += (n - 1) * a;
            break;
        }
        ll d = n % k;
        ll tmp = (n - n / k) * a;
        ll add = 0;
        add += d * a;
        n -= d;
        add += b;
        n /= k;
        add = min(add, tmp);
        res += add;
    }

    cout << res << "\n";

    return 0;
}