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

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;

    cin >> tt;

    while (tt--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        a = (a + c - 1) / c;
        b = (b + d - 1) / d;
        if (a + b <= k) {
            cout << a << " " << b << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}