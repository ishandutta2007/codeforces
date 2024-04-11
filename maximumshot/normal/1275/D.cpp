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

    while (tt--) {
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        if (a > b) swap(a, b);
        int ql = c - r;
        int qr = c + r;
        ql = max(ql, a);
        qr = min(qr, b);
        int res = b - a - max(0, qr - ql);
        cout << res << "\n";
    }

    return 0;
}