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

int factorize(int x) {
    int res = 0;
    for (int p = 2; p * p <= x; p++) {
        while (x % p == 0) {
            x /= p;
            res++;
        }
    }
    if (x > 1) res++;
    return res;
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
        int a, b, k;
        cin >> a >> b >> k;
        if (k == 1) {
            if (a != b && (a % b == 0 || b % a == 0)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            if (factorize(a) + factorize(b) >= k) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}