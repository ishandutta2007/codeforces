#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

bool check(ll n) {
    for (ll y, x = n; x > 0; x /= 10) {
        y = x % 10;
        if (y && n % y)
            return false;
    }
    return true;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        while (!check(n))
            n++;
        cout << n << "\n";
    }

    return 0;
}