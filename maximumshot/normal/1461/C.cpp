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

    cout.precision(20);
    cout << fixed;

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int R = n;
        while (R > 0 && a[R] == R)
            R--;
        ld res = 1;
        for (int i = 0; i < m; i++) {
            int r;
            ld p;
            cin >> r >> p;
            if (r >= R)
                res *= (1 - p);
        }
        if (R == 0)
            res = 0;
        cout << 1 - res << "\n";
    }

    return 0;
}