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

    ll a, b, c;

    cin >> a >> b >> c;

    if (a == b) {
        cout << 2 * (a + c) << "\n";
    } else {
        cout << 2 * (min(a, b) + c) + 1 << "\n";
    }

    return 0;
}