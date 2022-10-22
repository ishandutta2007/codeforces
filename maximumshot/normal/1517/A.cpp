#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        ll n;
        cin >> n;

        if (n % 2050ll) {
            cout << "-1\n";
            continue;
        }

        n /= 2050ll;

        ll res = 0;
        while (n > 0)
            res += n % 10, n /= 10;

        cout << res << "\n";
    }

    return 0;
}