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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    for (int ti = 0; ti < tt; ti++) {
        int n, k;
        cin >> n >> k;
        n += k;
        if (n % 2) {
            cout << "NO\n";
            continue;
        }
        n /= 2;
        if (1ll * k * (k + 1) / 2 <= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}